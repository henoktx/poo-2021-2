#pragma once

#include <iostream>

class Kid {
private:
    std::string nome;
    int idade;

public:
    Kid(std::string nome = "", int idade = 0) :
    nome(nome), idade(idade) {}

    void setNome(std::string nome) {
        this->nome = nome;
    }

    void setIdade(int idade) {
        this->idade = idade;
    }

    int getIdade() {
        return this->idade;
    }

    std::string getNome() {
        return this->nome;
    }

    friend std::ostream& operator<<(std::ostream& os, const Kid& x) {
        os << x.nome << "(" << x.idade << ")";
        return os;
    }
};