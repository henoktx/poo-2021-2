#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> remove(const vector<int>& vetor, int pessoa)
{
    vector<int> vetor_atualizado {vetor};

    vetor_atualizado.erase(find(vetor_atualizado.begin(), vetor_atualizado.end(), pessoa));

    return vetor_atualizado;
}

vector<int> insert(const vector<int>& vetor, int pessoa, int posicao)
{
    vector<int> vetor_atualizado {vetor};
    
    vetor_atualizado.insert(vetor_atualizado.begin() + posicao, pessoa);
    
    return vetor_atualizado;
}

vector<int> dance(const vector<int>& vetor)
{
    vector<int> vetor_atualizado {vetor};

    for (int i = 0; i < int(vetor_atualizado.size() - 1); i++) {
        for (int j = 0; j < int(vetor_atualizado.size() - 1); j++) {
            if (abs(vetor_atualizado[i]) == abs(vetor_atualizado[i + 1])) {
                vetor_atualizado.erase(find(vetor_atualizado.begin(), vetor_atualizado.end(), vetor_atualizado[i]));
                vetor_atualizado.erase(find(vetor_atualizado.begin(), vetor_atualizado.end(), vetor_atualizado[i]));
            } else {
                break;
            }
        }
    }
    
    return vetor_atualizado;
}