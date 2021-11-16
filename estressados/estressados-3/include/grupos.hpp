#pragma once 
#include <iostream>
#include <vector>

using namespace std;

int quantidade_casais(const vector<int>& vetor) 
{
    int casais = 0;
    vector<int> copy (vetor);
    
    for (int i = 0; i < int(copy.size()); i++) {
        if (copy[i] < 0) {
            auto posicao_homem = find(copy.begin(), copy.end(), abs(copy[i]));
            if (*posicao_homem == abs(copy[i])) {
                casais++;
                copy.erase(posicao_homem);
                copy.erase(copy.begin() + i);
                i = -1;
            }
        }
    }
    
    return casais;
}

int quantidade_trios(const vector<int>& vetor)
{
    vector<int> vetor_copy (vetor), represantes_trios {};
    int trios = 0;
    
    for (int i = 0; i < int(vetor_copy.size()) ; i++) {
        if (vetor_copy[i] < 0)
            vetor_copy[i] *= (-1);
    }

    for (int i = 0; i < int(vetor_copy.size()); i++) {
        if (count(vetor_copy.begin(), vetor_copy.end(), vetor_copy[i]) == 3 && find(represantes_trios.begin(), represantes_trios.end(), vetor_copy[i]) == represantes_trios.end()) {
            trios++;
            represantes_trios.push_back(vetor_copy[i]);
        }
    }
    
    return trios;
}
