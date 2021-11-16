#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <functional>

#define FPS 144

using namespace std; 
using namespace sf;


struct Pincel {
    Font font;
    Text text;
    RenderWindow& window;

    Pincel (RenderWindow& window) :
    window{window} {
        if(!font.loadFromFile("Inter-SemiBold.ttf")) 
            cout << "Erro no carregamento da fonte\n";
        text.setFont(font);
    }

    void write(string str, int x, int y, int size, Color color) {
        text.setString(str);
        text.setPosition(x, y);
        text.setCharacterSize(size);
        text.setFillColor(color);
        window.draw(text);
    }
};

struct Bubble {
    int x;
    int y;
    char letter;
    int speed;

    bool alive {true};
    static const int radius {20};

    Bubble(int x, int y, char letter, int speed) :
    x{x}, y{y}, letter{letter}, speed{speed} {}

    void update() 
    {
        y += speed;
    }

    void draw(RenderWindow& window)
    {
        CircleShape bubble(Bubble::radius);
        bubble.setPosition(x, y);
        bubble.setFillColor(Color::White);
        window.draw(bubble);

        static Pincel pincel(window);
        pincel.write(string(1, letter), x + 0.5 * Bubble::radius, y, Bubble::radius * 1.5, Color::Black);
    }

};

struct Board {
    RenderWindow& window;
    vector<Bubble> bubbles;
    Pincel pencil;
    
    int hits {0};
    int misses {0};

    Board(RenderWindow& window) :
    window{window}, pencil{window} {}

    void update()
    {
        if (this->check_new_bubble())
            this->add_new_bubble();
        
        for (Bubble& bubble : bubbles) {
            bubble.update();
        }

        this->mark_outside_bubbles();
        this->remove_dead_bubbles();
    }

    void remove_dead_bubbles() {
        vector<Bubble> vivas;
        
        for(Bubble& bubble : bubbles) {
            if (bubble.alive) {
                vivas.push_back(bubble);
            }
        }
        
        this->bubbles = vivas;
    }

    void mark_outside_bubbles() {
        for (Bubble& bubble : bubbles) {
            if (bubble.y + 2 * Bubble::radius > (int) this->window.getSize().y) {
                if (bubble.alive){
                    bubble.alive = false;
                    this->misses++;
                }
            }
        }
    }

    void mark_by_heat(char letter) {
        for (Bubble& bubble : bubbles) {
            if (bubble.letter == letter) {
                bubble.alive = false;
                this->hits++;
                break;
            }
            this->misses++;
        }
    }

    bool check_new_bubble() {
        static const int new_bubble_timeout {FPS + 10};
        static int new_bubble_timer {0};
        
        new_bubble_timer--;
        if (new_bubble_timer <= 0) {
            new_bubble_timer = new_bubble_timeout;
            return true;
        }
        return false;
    }

    void add_new_bubble() {
        int x = rand() % ((int) this->window.getSize().x - 2 * Bubble::radius);
        int y = -2 * Bubble::radius;
        int speed = rand() % 5 + 1;
        char letter = rand() % 26 + 'A';
        bubbles.push_back(Bubble(x, y, letter, speed));
    }
    
    void draw() 
    {
        pencil.write("Hits: " + to_string(this->hits) + " Misses: " + to_string(this->misses), 10, 10, 20, Color::White);
        pencil.write("Size: " + to_string(this->bubbles.size()), 10, 30, 20, Color::White);
        for (Bubble& bubble : bubbles) {
            bubble.draw(window);
        }
    }
};

struct Game {
    RenderWindow window;
    Board board;
    function<void()> on_upadte;

    Game() :
    window(VideoMode(1000,800), "Typing Game"), board(window) {
        this->on_upadte = [&]() {
            this->gameplay();
        };
        window.setFramerateLimit(FPS);
    }

    void process_events()
    {
        Event event;
        
        while(window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            } else if(event.type == Event::TextEntered) {
                char code = static_cast<char>(event.text.unicode);
                code = toupper(code);
                board.mark_by_heat(code);
            }
        }
    }
    
    void gameplay() 
    {
        Color azul_marinho (36,36,36);
        board.update();
        window.clear(azul_marinho);
        board.draw();
        window.display();
        if (board.misses >= 20) {
            this->on_upadte = [&]() {
                this->game_over();
                sleep(Time(seconds(1.5)));
                window.close();
            };
        }
    }

    void game_over()
    {
        Pincel pencil(window);
        Color vermelho (194,59,34);
        window.clear(vermelho);
        pencil.write("Game Over", 330, 350, 70, Color::White);
        window.display();
    }

    void main_loop()
    {
        while(window.isOpen()) {
            process_events();
            on_upadte();
        }
    }
};

int main() {
    Game game;
    game.main_loop();

    return 0;
}