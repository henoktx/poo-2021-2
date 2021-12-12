#pragma once

#include <sstream>
#include "transporte.hpp"

class Aviao : public Transporte {
private:
    int turbinas;
    bool trem_pouso;
    std::string destino;

public:
    Aviao(const int turbinas, const std::string destino, const float potencia_motor, const int capacidade, const int combustivel) :
    Transporte(potencia_motor, capacidade, combustivel) {
        this->turbinas = turbinas;
        this->trem_pouso = true;
        this->destino = destino;
    }

    void voar() {
        if (get_tanque() <= 0) {
            std::cout << "Tanque vazio, abastaceça para voar" << std::endl;
            return;
        } 

        if (get_potencia_motor() <= 0) {
            std::cout << "Motor batido, vá a um mecânico" << std::endl;
            return;
        }

        if (this->turbinas < 2) {
            std::cout << "Número de turbinas funcionando insuficiente para voar" << std::endl;
            return;
        }
        
        diminui_combustivel(50);
        this->trem_pouso = false;
        std::cout << "Calibrando flaps..." << std::endl;
        std::cout << "Trem de pouso recolhido" << std::endl;
        std::cout << "Voando para " << destino << std::endl;
    }

    void pousar() {
        if (!trem_pouso) {
            trem_pouso = true;
            std::cout << "Pousando em " << destino << std::endl;
            return;
        }

        std::cout << "O avião precisa estar voando para pousar" << std::endl;
    }

    void acidente() {
        trem_pouso = true;
        set_potencia_motor(0);
        turbinas = 0; 
        std::cout << "May day! Fazendo pouso forçado na água" << std::endl;    
    }

    void mecanico(const float potencia_motor, const int turbinas) {
        set_potencia_motor(potencia_motor);
        this->turbinas = turbinas;
        std::cout << "Motor e turbinas refeitos" << std::endl;
    }
    
    void set_turbinas(const int turbinas) {
        this->turbinas = turbinas;
    }

    void set_trem_pouso(bool x) {
        this->trem_pouso = x;
    }

    void set_destino(std::string destino) {
        this->destino = destino;
    }

    int get_turbinas() const {
        return this->turbinas;
    }

    bool get_trem_pouso() const {
        return this->trem_pouso;
    }

    std::string get_destino() const {
        return this->destino;
    }

    std::string to_string() const {
        std::stringstream ss; 
        ss << "Potência do motor: " << get_potencia_motor() << " | Capacidade: " << get_capacidade() << " pessoas | Tanque: " << get_tanque() << "L" << std::endl;
        ss << "Turbinas: " << this->turbinas << " | Trem de pouso: " << (this->trem_pouso ? "ativado" : "recolhido") << " | Destino: " << this->destino; 

        return ss.str();
    }
};