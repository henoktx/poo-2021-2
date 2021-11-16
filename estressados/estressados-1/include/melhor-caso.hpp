#pragma once
#include <iostream>
#include <vector>

using namespace std;

int procurar_menor(vector<int> fila)
{
    int menor = fila[0];
    
    for (int i = 0; i < int(fila.size()); i++) {
        if (fila[i] < menor)
            menor = fila[i];
    }

    return menor;
}

int procurar_menor_pos(vector<int> fila)
{
    int menor = 0;
    
    for (int i = 0; i < int(fila.size()); i++) {
        if (fila[i] < fila[menor])
            menor = i;
    }
    
    return menor;
}

int procurar_menor_pos_apartir(vector<int> fila, int inicio)
{
    int menor = 0;
    
    for (int i = inicio; i < int(fila.size()); i++) {
        if (fila[i] < fila[menor])
            menor = i;
    }
    
    return menor;
}

int procurar_melhor_se(vector<int> fila)
{
    int mais_calmo = -1;
    bool primeiro_homem = true;
    
    for (int i = 0; i < int(fila.size()); i++) {
        if (fila[i] > 0 && primeiro_homem) {
            primeiro_homem = false;
            mais_calmo = i;
        } else if (fila[i] > 0) {
            if (fila[i] < fila[mais_calmo]) {
                mais_calmo = i;
            }
        }
    }

    if (mais_calmo == -1) {
        return -1;
    } 

    return mais_calmo;
}
