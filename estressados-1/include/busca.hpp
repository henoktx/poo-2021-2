#pragma once
#include <iostream>
#include <vector>

using namespace std;

bool existe(vector<int> fila, int x) 
{
    for (int i = 0; i < int(fila.size()); i++) {
        if (fila[i] == x)
            return true;
    }

    return false;
}

int contar(vector<int> fila, int x)
{
    int vezes = 0;
    
    for (int i = 0; i < int(fila.size()); i++) {
        if (fila[i] == x) 
            vezes++;
    }

    return vezes;
}

int procular_valor(vector<int> fila, int x)
{
    for (int i = 0; i < int(fila.size()); i++) {
        if (fila[i] == x) {
            return i;
        }
    }

    return -1;
}

int procura_valor_apos(vector<int> fila, int x, int inicio)
{
    for (int i = inicio; i < int(fila.size()); i++) {
        if (fila[i] == x)
            return i;
    }

    return -1;
}