#pragma once

#include <iostream>
#include <map>

class Imedico;

class Ipaciente {
public:
    virtual ~Ipaciente() {}

    virtual void addMedico(Imedico *medico) = 0;

    virtual std::string getDiagnostico() = 0;

    virtual std::string getID() = 0;

    virtual std::map<std::string, Imedico*> getMedicos() = 0;

    virtual void removerMedico(const std::string &nome) = 0;
};