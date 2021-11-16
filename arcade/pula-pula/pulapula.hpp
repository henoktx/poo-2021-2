#pragma once 

#include <iostream>
#include <memory>
#include <list>
#include "kid.hpp"

class Trampolin {
private:
    std::list<std::shared_ptr<Kid>> espera {};
    std::list<std::shared_ptr<Kid>> pulando {};

public:
    Trampolin() {}

    void chegou(const std::shared_ptr<Kid> &kid) {
        this->espera.push_back(kid);
        std::cout << kid->getNome() << " entrou na fila de espera" << std::endl;
    }

    void entrou() {     
        if (this->espera.front() == nullptr) {
            std::cout << "Não há ninguém na fila" << std::endl;
            return;
        }
        
        this->pulando.push_back(this->espera.front());
        this->espera.pop_front();
        std::cout << *pulando.back() << " entrou no pula-pula" << std::endl;
    }

    void saiu() {
        if (this->pulando.front() == nullptr) {
            std::cout << "Não há ninguém no pula-pula" << std::endl;
            return;
        }
        
        this->espera.push_back(this->pulando.front());
        this->pulando.pop_front();
        std::cout << *espera.back() << " saiu do pula-pula" << std::endl;
    }

    Kid remove(std::string nome) {
        std::shared_ptr<Kid> kid {};
        Kid vazio;
        for (auto it_espera = espera.begin(); it_espera != espera.end(); it_espera++) {
            if ((*it_espera)->getNome() == nome) {
                kid = *it_espera;
                espera.erase(it_espera);    
                break;           
            }
        }
        for (auto it_pulando = pulando.begin(); it_pulando != pulando.end(); it_pulando++) {
            if ((*it_pulando)->getNome() == nome) {
                kid = *it_pulando;
                pulando.erase(it_pulando);                
                break;
            }
        }
        if (kid == nullptr) {
            std::cout << "Nenhum nome correspondente" << std::endl;
            return vazio;
        }
        std::cout << nome << " saiu do parque" << std::endl;

        return *kid;
    }

    friend std::ostream& operator<<(std::ostream& os, const Trampolin &list) {  
        int contador = 1;
        os << "Fila de espera [ ";
        for (auto it = list.espera.begin(); it != list.espera.end(); it++) {
            os << contador << " -> " << (*it)->getNome() << " | ";
            contador++;
        }
        os << " ]";
        os << " Pulando [ ";
        for (auto it = list.pulando.begin(); it != list.pulando.end(); it++) {
            os << (*it)->getNome() << " | ";
        }
        os << " ]";

        return os;
    }
};