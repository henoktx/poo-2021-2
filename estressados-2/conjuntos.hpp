#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> exclusivos(const vector<int>& vetor)
{   
    vector<int> selecionados {};

    for (int i = 0; i < int(vetor.size()); i++) {
        if (find(selecionados.begin(), selecionados.end(), vetor[i]) == selecionados.end())
            selecionados.push_back(vetor[i]);
    }
    
    return selecionados;
}

vector<int> diferentes(const vector<int>& vetor) 
{
    vector<int> selecionados {};

    for (int i = 0; i < int(vetor.size()); i++) {
        if (find(selecionados.begin(), selecionados.end(), abs(vetor[i])) == selecionados.end())
            selecionados.push_back(abs(vetor[i]));
    }
    
    return selecionados;
}

vector<int> abandonados(const vector<int>& vetor)
{
    vector<int> restantes, repetidos;

    for (int i = 0; i < int(vetor.size()); i++) {
        if (find(repetidos.begin(), repetidos.end(), vetor[i]) == repetidos.end())
            repetidos.push_back(vetor[i]);
        else
            restantes.push_back(vetor[i]);
    }

    return restantes;
}