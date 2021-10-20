#pragma once
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

vector<int> inverter_com_copia(const vector<int>& vetor_inicial)
{
    vector<int> copy_invertido {};

    for (int i = int(vetor_inicial.size() -1); i >= 0; i --) {
        copy_invertido.push_back(vetor_inicial[i]);
    }

    return copy_invertido;
}

void inverter_inplace(vector<int>& vetor)
{
    int tam = int(vetor.size()) - 1;
    
    for (int i = tam, j = 0; i > tam / 2; i--, j++) {
        swap(vetor[i], vetor[j]);
    }
}

int sortear(const vector<int>& vetor)
{
    srand(time(NULL));
    int sorteado {vetor[rand() % vetor.size() - 1]};

    return sorteado;
}

void embaralhar(vector<int>& vetor)
{
    random_shuffle(vetor.begin(), vetor.end());
}

void ordenar(vector<int>& vetor)
{
    for (int i = 0; i < int(vetor.size()) - 1; i++) {
        int menor = i;
        
        for (int j = i + 1; j < int(vetor.size()); j++) {
            if (vetor[menor] > vetor [j])
                menor = j;
        }

        if (menor != i)
            swap(vetor[i], vetor[menor]);
    }

}