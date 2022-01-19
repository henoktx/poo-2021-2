#pragma once 

#include <iostream>
#include <vector>
#include <memory>
#include "pessoa.hpp"

class Cinema {
private:
    std::vector<std::shared_ptr<Pessoa>> cadeira;

public:
    Cinema(int quantidade_cadeira) :
    cadeira(quantidade_cadeira, nullptr) {}

    void reservar(std::string nome,  std::string fone, int indice_cadeira) {
        if (indice_cadeira < 0 || indice_cadeira > (int) this->cadeira.size() - 1) {
            std::cout << "Cadeira " << indice_cadeira << " é inexistente" << std::endl;         
        } else if (this->cadeira[indice_cadeira] != nullptr) {
            std::cout << "Cadeira " << indice_cadeira << " já está ocupada" << std::endl;            
        } else {
            for (auto cliente : cadeira) {
                if (cliente == nullptr) {
                    continue;
                }
                if (cliente->getNome() == nome) {
                    std::cout << nome << " já está no cinema" << std::endl;
                    return;
                }
            }
            this->cadeira[indice_cadeira] = std::make_shared<Pessoa>(nome, fone);
            std::cout << "Reserva feita com sucesso" << std::endl;
        }
    }

    void cancelar(std::string nome) {
        for (int i = 0; i < (int) cadeira.size(); i++) {
            if (this->cadeira.at(i)->getNome() == nome) {
                std::cout << "Nome encontrado: " << this->cadeira.at(i)->getNome() << " | Cadeira: " << i << std::endl;
                this->cadeira.at(i) = nullptr;
                std::cout << "Reserva cancelada com sucesso" << std::endl;
                break;
            } else {
                std::cout << "Nome não encontrado" << std::endl;
                break;
            }
        }
    }

    std::vector<std::shared_ptr<Pessoa>> getCadeiras() {
        return this->cadeira;
    }
    
    friend std::ostream& operator<<(std::ostream& os, const Cinema& chair) {
        for (int i = 0; i < (int) chair.cadeira.size(); i++)  {
            if (chair.cadeira.at(i) == nullptr) {
                os << "Cadeira " << i << " -> [vazia] | ";
                continue;
            }  
            os << "Cadeira " << i << " -> " << chair.cadeira.at(i)->getNome() << " | ";
        }
        return os;
    }   
};