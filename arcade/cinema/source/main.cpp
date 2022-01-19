#include <iostream>
#include "../header/cinema.hpp"
#include "../header/funcionalidades.hpp"

int main() {
    Cinema cine(3);

    cine.reservar("Henok", "88988775685", 0); //reseva feita com sucesso
    cine.reservar("Henok", "88988775685", 1); //já está no cinema
    cine.reservar("jontas", "88988775685", 0); //cadeira ocupada
    cine.reservar("hugo", "88988775685", 10); //cadeira inexistente
    cine.cancelar("rita"); //nome nao encontrado
    cine.cancelar("Henok"); //cancelamento feito
    cine.reservar("freitag", "88988775685", 0); //reserva com sucesso
    cine.reservar("José", "88988158237", 2); //reserva feita com sucesso
    cine.cancelar("Henok"); //nome nao encontrado

    std::cout << std::endl;

    std::cout << cine.getCadeiras() << std::endl;
    
    return 0;
}