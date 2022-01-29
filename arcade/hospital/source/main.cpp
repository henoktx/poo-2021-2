#include <sstream>
#include <vector>
#include "../header/hospital.hpp"
#include "../../../cpp_functional-master/auxiliar.hpp"

int main() {
    Hospital regional;
    while (true) {
        std::string line{}, cmd{};
        std::getline(std::cin, line);
        std::stringstream ss(line);
        ss >> cmd;
        std::cout << "$" << line << std::endl;
        if (cmd != "end") {std::cout << std::endl;}

        if (cmd == "end") {
            break;
        } else if (cmd == "addPacs") {
            std::string aux;
            std::vector<std::string> vectorString;
            while (ss >> aux) {
                vectorString = aux::split(aux, ':');
                try {regional.addPaciente(vectorString.front(), vectorString.back());}
                catch (std::string &error) {std::cout << error << "\n\n";}
            }
        } else if (cmd == "addMeds") {
            std::string aux;
            std::vector<std::string> vectorString;
            while (ss >> aux) {
                vectorString = aux::split(aux, ':');
                try {regional.addMedico(vectorString.front(), vectorString.back());}
                catch (std::string &error) {std::cout << error << "\n\n";}
            }
        } else if (cmd == "show") {
            std::cout << regional << std::endl;
        } else if (cmd == "tie") {
            std::string med, pacs;
            ss >> med;
            while (ss >> pacs) {
                try {regional.vincular(med, pacs);}
                catch (std::string &error) {std::cout << error << "\n\n";}
            }
        } else if (cmd == "rmMed") {
            std::string nome;
            ss >> nome;
            try {regional.removeMedico(nome);}
            catch (std::string &error) {std::cout << error << "\n\n";}
        } else if (cmd == "rmPac") {
            std::string nome;
            ss >> nome;
            try {regional.removePaciente(nome);}
            catch (std::string &error) {std::cout << error << "\n\n";}
        } else {
            std::cout << "Invalid command\n\n";
        }
    }    
    return 0;
}