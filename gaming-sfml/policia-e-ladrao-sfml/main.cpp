#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#ifdef _WIN32
  #include <windows.h>
#else
  #include <unistd.h>
#endif

using namespace std;
using namespace sf;

void setSize(Sprite& sprite, int width, int height) 
{
    auto dim = sprite.getLocalBounds();
    sprite.setScale((float) width / dim.width, (float) height / dim.height);
}

struct Entity {
    int x {0};
    int y {0};
    int step{0};
    Sprite sprite;

    Entity(int x, int y, int step, Texture& texture):
        x {x}, y {y}, step {step}, sprite(texture) {
        sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
        this->sprite.setTexture(texture);
        setSize(this->sprite, step, step);
    }
    
    void draw(RenderWindow& window) 
    {
        this->sprite.setPosition(x * step, y * step);
        window.draw(this->sprite);
    }

};

struct Board {
    int nc {0};
    int nl {0};
    int step {0};
    Sprite sprite;
    RectangleShape rect;

    Board(int nc, int nl, int step, Texture& texture) 
    {
        this->nc = nc;
        this->nl = nl;
        this->step = step;
        this->sprite.setTexture(texture);
        setSize(this->sprite, nc * step, nl * step);
        this->sprite.setPosition(0, 0);

        this->rect.setSize(sf::Vector2f(step, step));
        this->rect.setFillColor(sf::Color::Transparent);
        this->rect.setOutlineColor(sf::Color::Black);
        this->rect.setOutlineThickness(2);
    }
    void draw(RenderWindow& window) {
        window.draw(this->sprite);
    }
};

void moveEntity(Keyboard::Key key, Entity& entity, vector<Keyboard::Key> move_keys) 
{
    if (key == move_keys[0]) {
        entity.sprite.setRotation(-90);
        entity.x--;
    } else if (key == move_keys[1]) {
        entity.sprite.setRotation(0);
        entity.y--;
    } else if (key == move_keys[2]) {
        entity.sprite.setRotation(90);
        entity.x++;
    } else if (key == move_keys[3]) {
        entity.sprite.setRotation(-180);
        entity.y++;
    }
}

Texture loadtexture(string path) 
{
    Texture texture;
    if (!texture.loadFromFile(path)) {
        cout << "Error loading texture" << endl;
        exit(1);
    }

    return texture;
}

void loadMusic(string path, Music& musica) 
{
    if (!musica.openFromFile(path)) {
        cout << "Error loading music" << endl;
        exit(1);
    }
}

void playMusic(Music& musica)
{
    musica.setLoop(true);
    musica.play();
    musica.setVolume(25);
}

int main() {
    const int STEP {100};
    
    RenderWindow window(VideoMode(1000, 600), "Policia e Ladrao");

    Texture rua_tex { loadtexture("images/rua.png") };
    Texture policial_tex { loadtexture("images/carro-policia.png") };
    Texture ladrao_tex { loadtexture("images/carro-ladrao.png") };

    Entity policial(1, 1, STEP, policial_tex);
    Entity ladrao(3, 3, STEP, ladrao_tex);
    Board rua(10, 6, STEP, rua_tex);

    Music sirene, batida;

    loadMusic("sounds/sirene-policia.ogg", sirene);
    loadMusic("sounds/batida-carro.ogg", batida);
    playMusic(sirene);

    while (window.isOpen()) {
        Event event;

        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            } else if (event.type == Event::KeyPressed) {
                moveEntity(event.key.code, policial, {Keyboard::Left, Keyboard::Up, Keyboard::Right, Keyboard::Down});
                moveEntity(event.key.code, ladrao, {Keyboard::A, Keyboard::W, Keyboard::D, Keyboard::S});
            }
        }     

        window.clear();
        rua.draw(window);
        policial.draw(window);
        ladrao.draw(window);
        window.display();

        if (policial.x == ladrao.x && policial.y == ladrao.y) {
            sirene.pause();
            playMusic(batida);
            sleep(2);
            window.close();
        }
    }

}

