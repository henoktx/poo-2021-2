#pragma once

#include <iostream>
#include <sstream>

class Fone {
private:
    std::string id;
    std::string numero;

    static bool valida_char(char c, std::string s) {
        bool eh_valido = false;
        for (const auto& i : s) {
            if (i == c) {
                eh_valido = true;
            }
        }
        return eh_valido;
    }

public:
    Fone(std::string id, std::string numero) :
    id(id), numero(numero) {}

    bool valida_numero(std::string numero) {
        std::string caracteres_validos {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '(', ')'};
        std::string caracteres_invalidos {};
        bool eh_valido {true};
        for (auto i : numero) {
            if (!valida_char(i, caracteres_validos)) {
                caracteres_invalidos.push_back(i);
                eh_valido = false;
            }
        }  
        if (!eh_valido) {
            std::cout << "Número inválido -> caracteres inválidos [ " << caracteres_invalidos << " ]" << std::endl;
        } else {
            std::cout << "Número válido" << std::endl;
        }
        return eh_valido;
    }

    std::string toString() {
        std::stringstream ss;
        ss << "ID - " << this->id << " | Número - " << this->numero;
        return ss.str();
    }

    void setId(std::string id) {
        this->id = id;
    }

    void setNumero(std::string numero) {
        this->numero = numero;
    }

    std::string getId() {
        return this->id;
    }

    std::string getNumero() {
        return this->numero;
    }
};