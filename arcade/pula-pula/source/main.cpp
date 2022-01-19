#include <iostream>
#include "../header/pulapula.hpp"

int main() {
    
    auto kid1 = std::make_shared<Kid>("henok", 18);
    auto kid2 = std::make_shared<Kid>("hugo", 5);
    Trampolin pula;

    pula.chegou(kid1); //henok na fila
    pula.chegou(kid2); //hugo na fila

    std::cout << pula << std::endl << std::endl;

    pula.entrou(); //henok no pula-pula
    pula.entrou(); //hugo no pula-pula

    std::cout << pula << std::endl << std::endl;

    pula.saiu(); //henok saiu
    pula.saiu(); //hugo saiu
    pula.entrou(); //henok entrou

    std::cout << pula << std::endl << std::endl;

    pula.remove("huo"); //nenhum nome correspondente
    pula.remove("hugo"); //hugo deixou o parque
    std::cout << pula << std::endl << std::endl;

    pula.entrou(); //ninguem na fila
    std::cout << pula << std::endl << std::endl;
    
    pula.saiu(); //henok saiu
    pula.saiu(); //ninguem pulando
    std::cout << pula << std::endl;
    
    return 0;
}