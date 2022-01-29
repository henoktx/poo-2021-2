#include <iostream>
#include <iomanip>
#include <map>
#include "Imedico.hpp"
#include "Ipaciente.hpp"

class Paciente : public Ipaciente {
private:
    std::string diagnostico;
    std::map<std::string, Imedico*> medicos;
    std::string nome;

public:
    Paciente(const std::string &nome, const std::string &diagnostico) :
    diagnostico{diagnostico}, medicos{}, nome{nome} {}

    void addMedico(Imedico *medico) override {
        bool check{false};
        for (auto &[nome, medic] : medicos) {
            if (medic->getClasse() == medico->getClasse()) {
                check = true;
                throw std::string("Já existe outro medico dessa especialidade");
            }
        }
        if (check) {
            return;
        }
        else {
            auto &&[it, added] = this->medicos.insert({medico->getID(), medico});
            if (!added) {throw std::string("Erro ao adicionar");}
        }
    }

    std::string getDiagnostico() override {return this->diagnostico;}

    std::string getID() override {return this->nome;}

    std::map<std::string, Imedico*> getMedicos() override {
        return this->medicos;
    }

    void removerMedico(const std::string &nome) override {
        auto it = this->medicos.find(nome);
        if (it != this->medicos.end()) {
            this->medicos.erase(it->first);
            return;
        }
        throw std::string("Médico não removido");
    }

    friend std::ostream& operator<<(std::ostream& os, const Paciente paciente) {
        std::string aux;
        aux = "Pac: " + paciente.nome + ":" + paciente.diagnostico;
        os << aux << std::setw(40 - aux.length()) << "Meds: [";
        int count{0};
        for (auto &[nome, medic] : paciente.medicos) {
            if (count++ > 0) {os << ", ";}
            os << medic->getID();
        } 
        os << "]";
        return os;
    }
};