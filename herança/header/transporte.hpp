#pragma once

#include <iostream>

class Transporte {
private: 
    float potencia_motor;
    int capacidade;
    int tanque;

protected:    
    void diminui_combustivel(const int quantidade) {
        if (this->tanque - quantidade < 0) {
            this->tanque = 0;
        }
        this->tanque -= quantidade;
    }

public:
    Transporte(const float potencia_motor, const int capacidade, const int combustivel) {
        this->potencia_motor = potencia_motor;
        this->capacidade = capacidade;
        this->tanque = combustivel;
    }

    virtual void acidente() {
        potencia_motor = 0;
        std::cout << "Transporte envolvido em um acidente" << std::endl;
    }

    virtual void mecanico(const float potencia_motor) {
        this->potencia_motor = potencia_motor;
        std::cout << "Motor refeito" << std::endl;
    }

    void abastecer(const int combustivel) {
        this->tanque += combustivel;
        std::cout << "Tanque abastecido com " << combustivel << "L" << std::endl;
    }

    void set_potencia_motor(const float potencia_motor) {
        this->potencia_motor = potencia_motor;
    }

    void set_capacidade(const int capacidade) {
        this->capacidade = capacidade;
    }

    void set_tanque(const int combustivel) {
        this->tanque = combustivel;
    }

    float get_potencia_motor() const {
        return this->potencia_motor;
    }

    int get_capacidade() const {
        return this->capacidade;
    }

    int get_tanque() const {
        return this->tanque;
    }
};