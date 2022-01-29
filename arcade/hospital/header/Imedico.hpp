#pragma once

#include <iostream>
#include <map>

class Ipaciente;

class Imedico {
public:
    virtual ~Imedico() {}

    virtual void addPaciente(Ipaciente *paciente) = 0;

    virtual std::string getClasse() = 0;

    virtual std::string getID() = 0;

    virtual std::map<std::string, Ipaciente*> getPacientes() = 0;

    virtual void removerPaciente(const std::string &nome) = 0;
};