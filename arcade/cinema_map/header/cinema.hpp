#pragma once 

#include <iostream>
#include <memory>
#include <map>
#include "pessoa.hpp"
#include "funcionalidades.hpp"

class Cinema {
private:
    std::map<int, std::shared_ptr<Pessoa>> cadeira;
    int quantididade_cadeira;

public:
    Cinema(int quantidade_cadeira) {
        this->quantididade_cadeira = quantidade_cadeira;
    }

    void reservar(std::string nome, std::string fone, int indice_cadeira) {
        if (indice_cadeira < 0 || indice_cadeira > this->quantididade_cadeira) {
            std::cout << "Cadeira " << indice_cadeira << " é inexistente" << std::endl;         
        } else if (this->cadeira.find(indice_cadeira) != cadeira.end()) {
            std::cout << "Cadeira " << indice_cadeira << " já está ocupada" << std::endl;            
        } else {
            for (auto cliente : cadeira) {
                if (cliente.second->getNome() == nome) {
                    std::cout << nome << " já está no cinema" << std::endl;
                    return;
                }
            }
            this->cadeira.insert(std::make_pair(indice_cadeira, std::make_shared<Pessoa>(nome, fone)));
            std::cout << "Reserva feita com sucesso" << std::endl;
        }
    }

    void cancelar(std::string nome) {
        for (auto cliente : cadeira) {
            if (cliente.second->getNome() == nome) {
                std::cout << "Nome encontrado: " << cliente.second->getNome() << " | Cadeira: " << cliente.first << std::endl;
                this->cadeira.erase(cliente.first);
                std::cout << "Reserva cancelada com sucesso" << std::endl;
                break;
            } else {
                std::cout << "Nome não encontrado" << std::endl;
                break;
            }
        }
    }

    std::map<int, std::shared_ptr<Pessoa>> getCadeiras() {
        return this->cadeira;
    }
    
    friend std::ostream& operator<<(std::ostream& os, const Cinema& chair) {
        for (int i = 0; i < chair.quantididade_cadeira; i++)  {
            if (chair.cadeira.find(i) == chair.cadeira.end()) {
                os << "Cadeira " << i << " -> [vazia] | ";
                continue;
            }  
            os << "Cadeira " << i << " -> " << *chair.cadeira.at(i) << " | ";
        }
        return os;
    }   
};