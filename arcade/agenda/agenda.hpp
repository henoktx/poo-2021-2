#pragma once

#include <algorithm>
#include "../contatos/contato.hpp"

class Agenda {
private:
    std::list<std::shared_ptr<Contato>> contatos {};

    int procuraPos(const std::string &nome) {
        int contador {0};
        for (auto it = contatos.begin(); it != contatos.end(); it++) {
            if (nome == (*it)->getName()) {
                return contador;
            }
            contador++;
        }
        return -1;
    }

    void sort() {
        auto nome = contatos.begin();
        auto contador = contatos.begin();
        for (auto it = contatos.begin(); it != contatos.end(); it++) {
            for (auto it2 = contador; it2 != contatos.end(); it2++) {
                if ((*it2)->getName() < (*nome)->getName()) {
                    nome = it2;
                }
            }
            std::swap(*contador, *nome);
            contador++;
            nome = contador;
        }
    }

public:
    Agenda() {}

    void addContato(std::shared_ptr<Contato> &contato) {
        for (auto it = contatos.begin(); it != contatos.end(); it++) {
            if (contato->getName() == (*it)->getName()) {
                for (auto i : contato->getFones()) {
                    (*it)->addFone(i);
                    std::cout << "Contato adicionado com sucesso" << std::endl;
                    return;
                }
            } 
        }
        contatos.push_back(contato);
        std::cout << "Contato adicionado com sucesso" << std::endl;
    }

    void rmContato(const std::string &nome) {
        for (auto it = contatos.begin(); it != contatos.end(); it++) {
            if (nome == (*it)->getName()) {
                contatos.erase(it);
                std::cout << "Contato removido com sucesso" << std::endl;
                return;
            }
        } 
        std::cout << nome << " não corresponde a nenhum contato da agenda" << std::endl; 
    }
    
    std::shared_ptr<Contato> getContato(const std::string &nome) {     
        std::list<std::shared_ptr<Fone>> vazia;
        auto vazio = std::make_shared<Contato>(" ", vazia);
        for (auto it = contatos.begin(); it != contatos.end(); it++) {
            if (nome == (*it)->getName()) {
                std::cout << "Contato encontrado: " << (*it)->toString() << std::endl;
                return *it;                
            }
        }        
        std::cout << nome << " não corresponde a nenhum contato da agenda" << std::endl;
        return vazio;
    }

    std::list<std::shared_ptr<Contato>> procura(const std::string &pattern) {
        std::list<std::shared_ptr<Contato>> encontrados {};
        for (auto it = contatos.begin(); it != contatos.end(); it++) {
            std::string parte = (*it)->getName();
            if (parte.find(pattern) != std::string::npos) {
                encontrados.push_back(*it);
                std::cout << (*it)->toString() << std::endl;
            }
        }
        if ((int) encontrados.size() <= 0) {
            if ((int) contatos.size() <= 0) {
                std::cout << "Não há contatos na agenda" << std::endl;
                return encontrados;
            } 
            std::cout << "Nenhuma correspondência a " << pattern << std::endl;
        }
        return encontrados;
    }

    std::list<std::shared_ptr<Contato>> getContatos() {
        return this->contatos;
    }
    
    std::string toString() {
        sort();
        std::stringstream ss;
        for (auto it = this->contatos.begin(); it != this->contatos.end(); it++) {
            ss << **it << std::endl;       
        }
        return ss.str();
    }
};