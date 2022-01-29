#pragma once

#include <iostream>
#include <iomanip>
#include <map>
#include "Imedico.hpp"
#include "Ipaciente.hpp"

class Medico : public Imedico {
private:
    std::string classe;
    std::map<std::string, Ipaciente*> pacientes;
    std::string nome;

public:
    Medico(const std::string &nome, const std::string &classe) :
    classe{classe}, pacientes{}, nome{nome} {}

    void addPaciente(Ipaciente *paciente) override {
        for (auto i : paciente->getMedicos()) {
            if (i.second->getClasse() == this->classe) {
                throw std::string("Dois médicos com especialidade igual, não podem ter o mesmo paciente");
                return;
            }
        }
        if (paciente->getID() == this->pacientes.find(paciente->getID())->first) {
            throw std::string("Já existe um paciente com esse nome na lista desse médico");
        } else {
            auto &&[it, added] = this->pacientes.insert({paciente->getID(), paciente});
            if (!added) {throw std::string("Erro ao adicionar");}
        }
    }

    std::string getClasse() override {return this->classe;}

    std::string getID() override {return this->nome;}

    std::map<std::string, Ipaciente*> getPacientes() override {
        return this->pacientes;
    }

    void removerPaciente(const std::string &nome) {
        auto it = this->pacientes.find(nome);
        if (it != this->pacientes.end()) {
            this->pacientes.erase(it->first);
            return;
        }
        throw std::string("Paciente não removido");
    }

    friend std::ostream& operator<<(std::ostream& os, const Medico medico) {
        std::string aux;
        aux = "Med: " + medico.nome + ":" + medico.classe;
        os << aux << std::setw(40 - aux.length()) << "Pacs: [";
        int count{0};
        for (auto &[nome, pacient] : medico.pacientes) {
            if (count++ > 0) {os << ", ";}
            os << pacient->getID();
        } 
        os << "]";
        return os;
    }
};

