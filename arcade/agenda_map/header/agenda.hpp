#pragma once

#include <algorithm>
#include <list>
#include <map>
#include "../../contatos/header/contato.hpp"

class Agenda {
private:
    std::map<std::string, std::shared_ptr<Contato>> contatos {};

    int procuraPos(const std::string &nome) {
        int contador {0};
        for (auto i : this->contatos) {
            if (nome == i.second->getName()) {
                return contador;
            }
            contador++;
        }
        return -1;
    }

public:
    Agenda() {}

    void addContato(std::shared_ptr<Contato> &contato) {
        for (auto it = contatos.begin(); it != contatos.end(); it++) {
            if (contato->getName() == it->second->getName()) {
                for (auto i : contato->getFones()) {
                    it->second->addFone(i);
                    std::cout << "Contato adicionado com sucesso" << std::endl;
                    return;
                }
            } 
        }
        contatos.insert(std::make_pair(contato->getName(), contato));
        std::cout << "Contato adicionado com sucesso" << std::endl;
    }

    void rmContato(const std::string &nome) {
        for (auto it = contatos.begin(); it != contatos.end(); it++) {
            if (nome == it->second->getName()) {
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
            if (nome == it->second->getName()) {
                std::cout << "Contato encontrado: " << it->second->toString() << std::endl;
                return it->second;                
            }
        }        
        std::cout << nome << " não corresponde a nenhum contato da agenda" << std::endl;
        return vazio;
    }

    std::list<std::shared_ptr<Contato>> procura(const std::string &pattern) {
        std::list<std::shared_ptr<Contato>> encontrados {};
        for (auto it = contatos.begin(); it != contatos.end(); it++) {
            std::string parte = it->second->getName();
            if (parte.find(pattern) != std::string::npos) {
                encontrados.push_back(it->second);
                std::cout << it->second->toString() << std::endl;
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

    std::map<std::string, std::shared_ptr<Contato>> getContatos() {
        return this->contatos;
    }
    
    std::string toString() {
        std::stringstream ss;
        for (auto it = this->contatos.begin(); it != this->contatos.end(); it++) {
            ss << *it->second << std::endl;       
        }
        return ss.str();
    }
};