#include <iostream>
#include <algorithm>

using namespace std;

struct Pessoa {
    string name;
    int age;

    Pessoa(string name, int age) :
    name (name), age (age) {}

};

struct Moto {
    Pessoa* pessoa {nullptr};
    int power {0};
    int time {0};
    bool tem_alguem {false};

    Moto(int power = 1) :
    power (power) {}

    void dados_moto() 
    {
        cout << "\nMoto sendo inicializada" << endl;
        cout << "Potência: " << power << endl;
        cout << "Minutos restantes: " << time << endl;
        cout << "Tem pessoa: " << (tem_alguem ? "não\n" : "sim\n");
    }
    
    void comprar_tempo(int time)
    {
        this->time = time;
        cout << endl << "Tempo comprado com sucesso!" << endl;
    }
    
    void descer()
    {   
        if(tem_alguem) {
            tem_alguem = false;
            cout << pessoa->name << " desceu da moto" << endl;
            pessoa = nullptr;
        }
    }
    
    void subir(Pessoa* pessoa) 
    {
        if (!tem_alguem) {
            this->pessoa = pessoa;
            tem_alguem = true;
            cout << endl << this->pessoa->name << " subiu na moto" << endl;
        }
    }

    void dirigir(int time) 
    {
        if (tem_alguem == true) {
            if (pessoa->age <= 10 && time > 0) {
                cout << pessoa->name << " está dirigindo agora\n" << endl;
                if (time > this->time) {
                    cout << "O tempo acabou. Você andou por " << this->time << " minutos" << endl;
                    this->time = 0;
                } else if (time < this->time) {
                    cout << "O tempo acabou. Você andou por " << time << " minutos" << endl;
                    cout << "Ainda há " << (this->time - time) << " minutos sobrando" << endl;
                } else if(time == this->time) {
                    cout << "O tempo acabou. Você andou por " << time << " minutos" << endl;
                }
            } else if (pessoa->age <= 10 && time <= 0) {
                cout << "Desculpe, moto sem tempo" << endl;
                descer();
            } else if(pessoa->age > 10) {
                cout << "Idade de " << pessoa->name << " não aceita" << endl;
                descer();
            }
        }
    }

    void buzinar() 
    {
        if (tem_alguem == true) {
            cout << "\nP";
            string es(this->power, 'e');
            cout << es << "m" << endl;
        } else {
            cout << "\nSem ninguém para buzinar a moto" << endl;
        }
    }
};

int main() {
    Pessoa p1("Hugo", 10);
    Pessoa p2("Freitag", 9);

    Moto m1(2);
    Moto m2(3);

    m1.dados_moto();
    m1.comprar_tempo(15);
    m1.subir(&p1);
    m1.dirigir(15);
    m1.buzinar();

    m2.dados_moto();
    m2.comprar_tempo(15);
    m2.subir(&p2);
    m2.dirigir(10);
    m2.buzinar();
        
    return 0;
}