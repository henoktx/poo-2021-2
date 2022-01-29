#pragma once

#include <iostream>
#include <map>
#include "paciente.hpp"
#include "medico.hpp"

class Hospital {
public:
    void addPaciente(const std::string &nome, const std::string &diagnostico) {
        if (this->pacientes.find(nome)->first == nome) {
            throw std::string("Paciente não pode ser adicionado duas vezes no hospital");
        } else {
            Ipaciente *paciente = new Paciente(nome, diagnostico);
            this->pacientes.insert({nome, paciente});
        }
    }

    void addMedico(const std::string &nome, const std::string &classe) {
        if (this->medicos.find(nome)->first == nome) {
            throw std::string("Medico não pode ser adicionado duas vezes no hospital");
        } else {
            Imedico *medico = new Medico(nome, classe);
            this->medicos.insert({nome, medico});
        }
    }

    void removeMedico(const std::string &nome) {
        auto it = this->medicos.find(nome);
        if (it->first == nome) {
            for (auto i : it->second->getPacientes()) {
                i.second->removerMedico(it->first);
            }
            delete it->second;
            this->medicos.erase(it->first);
            return;
        }
        throw std::string("Médico não encontrado");
    }

    void removePaciente(const std::string &nome) {
        auto it = this->pacientes.find(nome);
        if (it->first == nome) {
            for (auto i : it->second->getMedicos()) {
                i.second->removerPaciente(it->first);
            }
            delete it->second;
            this->pacientes.erase(it->first);
            return;
        }
        throw std::string("Paciente não encontrado");
    }    

    void vincular(const std::string &nomeMedico, const std::string &nomePaciente) {
        auto med = this->medicos.find(nomeMedico);
        auto pac = this->pacientes.find(nomePaciente);
        if (med == medicos.end() || pac == pacientes.end()) {
            throw std::string("Médico ou paciente não encontrado");
        }
        try {
            med->second->addPaciente(pac->second);
            pac->second->addMedico(med->second);
        } catch (std::string &error) { 
            std::cout << error << "\n\n";
        } 
    }

    friend std::ostream& operator<<(std::ostream& os, const Hospital hospital) {        
        for (auto j : hospital.pacientes) {
            os << *static_cast<Paciente*>(j.second) << std::endl;
        }
        for (auto i : hospital.medicos) {
            os << *static_cast<Medico*>(i.second) << std::endl;
        }
        return os;
    }

private:
    std::map<std::string, Ipaciente*> pacientes;
    std::map<std::string, Imedico*> medicos;
};