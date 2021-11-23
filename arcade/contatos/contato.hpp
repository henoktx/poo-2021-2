#pragma once 

#include <sstream>
#include <memory>
#include <list>
#include "fone.hpp"

class Contato {
private:
    std::string nome;
    std::list<std::shared_ptr<Fone>> fones;
    std::string prefix {"- "};

public:
    Contato(std::string nome, std::list<std::shared_ptr<Fone>> fones) :
    nome(nome), fones(fones) {}

    void addFone(std::shared_ptr<Fone> fone) {
        if(fone->valida_numero(fone->getNumero())) {
            this->fones.push_back(fone);
            std::cout << "Número adicionado com sucesso" << std::endl;
        } 
    }

    void removeFone(int index) {
        for (auto it = this->fones.begin(); it != this->fones.end(); it++) {
            if (std::distance(this->fones.begin(), it) == index) {
                this->fones.erase(it);
                std::cout << "Remoção feita com sucesso" << std::endl;
            }
        }
    }

    std::string toString() {
        std::stringstream ss;
        int index {0};
        ss << prefix << this->nome;
        for (auto it = this->fones.begin(); it != this->fones.end(); it++) {
            ss << " [" << index << ":" << (*it)->getId() << ":" << (*it)->getNumero() << "]";
            index++;
        }
        return ss.str();
    }

    friend std::ostream& operator<<(std::ostream &os, Contato a) {
        os << a.toString();
        return os;
    }

    void setName(std::string nome) {
        this->nome = nome;
        std::cout << "Nome setado com sucesso" << std::endl;
    }

    std::string getName() const {
        return this->nome;
    }

    std::list<std::shared_ptr<Fone>> getFones() const {
        return fones;
    }
};