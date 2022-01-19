#pragma once

#include <iostream>

class Pessoa {
public:
    std::string nome;
    std::string fone;

    Pessoa(std::string nome, std::string fone) : 
    nome(nome), fone(fone) {}

    friend std::ostream& operator<<(std::ostream& os, const Pessoa x) {
        os << "Nome: " << x.nome << " | Telefone: " << x.fone;
        return os;
    }

    void setNome(std::string nome) {
        this->nome = nome;
    }

    void setFone(std::string fone) {
        this->fone = fone;
    }

    std::string getNome() {
        return this->nome;
    }
    
    std::string getFone() {
        return this->fone;
    }
};