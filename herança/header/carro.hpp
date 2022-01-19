#pragma once

#include <cstdlib>
#include <ctime>
#include <sstream>
#include "transporte.hpp"

class Carro : public Transporte {
private:
    int pneus;
    int step;
    bool farol;
    bool ar_condicionado;

public:
    Carro(const float potencia_motor, const int capacidade, const int combustivel) : 
    Transporte(potencia_motor, capacidade, combustivel) {
        this->pneus = 4;
        this->step = 1;
        this->farol = false;
        this->ar_condicionado = false;
    }

    void locomover() {
        if (get_tanque() <= 0) {
            std::cout << "Tanque vazio, abastaceça para se locomover" << std::endl;
            return;
        } 

        if (get_potencia_motor() <= 0) {
            std::cout << "Motor batido, vá a um mecânico" << std::endl;
            return;
        }
        
        if (pneus < 4) {
            std::cout << "Pneu furado, utilize o step ou vá ao mecânico" << std::endl;
            return;
        }
        
        if (get_potencia_motor() >= 2.0) {
            diminui_combustivel(3);
        } else {
            diminui_combustivel(1);
        }

        std::cout << "Carro passeando pela cidade" << std::endl;
    }

    void drift() {
        if ((pneus < 4) || (get_tanque() < 2) || (get_potencia_motor() == 0)) {
            std::cout << "Carro impossibilitado de fazer drift" << std::endl;
            return;
        }

        std::srand(std::time(NULL));
        int chance = rand()%2;
        
        this->diminui_combustivel(2);
        std::cout << "DK está na área" << std::endl;
        if(chance == 1) {
            --this->pneus;
            std::cout << "Pneu estourou enquanto fazia drift" << std::endl;
        }
    }

    void usa_step() {
        if (this->pneus < 4) { 
            if (this->step == 1) {
                --step;
                pneus++;
                std::cout << "Pneu furado trocado pelo step" << std::endl;
                return;
            }
            std::cout << "Step indisponível, vá ao mecânico" << std::endl;
        }
        std::cout << "Não há pneus furados para trocar com o step" << std::endl;
    }
    
    void mecanico(const float potencia_motor = 0) {
        if (get_potencia_motor() == 0) {
            set_potencia_motor(potencia_motor);
            std::cout << "Motor refeito" << std::endl;
        }
        if (this->pneus < 4 || this->step == 0) {
            this->pneus = 4;
            this->step = 1;
            std::cout << "Pneus remendados" << std::endl;
        }   
    }

    void liga_farol() {
        this->farol = true;
        std::cout << "Farol ligado" << std::endl;
    }
    
    void desliga_farol() {
        if (this->farol) {
            this->farol = false;
            std::cout << "Farol desligado" << std::endl;
        }
    }

    void liga_ar_condicionado() {
        this->ar_condicionado = true;
        std::cout << "Ar-condicionado ligado" << std::endl;
    }

    void desliga_ar_condicionado() {
        if (this->ar_condicionado) {
            this->ar_condicionado = false;
            std::cout << "Ar-condicionado desligado" << std::endl;
        }
    }

    int get_pneus() const {
        return this->pneus;
    }

    int get_step() const {
        return this->step;
    }

    bool get_ar_condicionado() const {
        return this->ar_condicionado;
    }

    bool get_farol() const {
        return this->farol;
    }

    void set_pneus(int pneus) {
        if (pneus > 4) {
            this->pneus = 4;
            return;
        } else if (pneus < 0) {
            return;
        }

        this->pneus = pneus;
    }

    void set_step() {
        this->step = 1;
    }

    void set_ar_condicionado(bool x) {
        this->ar_condicionado = x;
    }

    void set_farol(bool a) {
        this->farol = a;
    }

    std::string to_string() const {
        std::stringstream ss; 
        ss << "Potência do motor: " << get_potencia_motor() << " | Capacidade: " << get_capacidade() << "pessoas | Tanque: " << get_tanque() << "L" << std::endl;
        ss << "Pneus: " << this->pneus << " | Step: " << this->step << " | Farol: " << (this->farol ? "ligado" : "desligado") << " | Ar-condicionado: " << (this->ar_condicionado ? "ligado" : "desligado"); 

        return ss.str();
    }
};