#pragma once
#include <iostream>
#include <vector>

using namespace std;

int briga(const vector<int>& vetor)
{
    int quantidade_brigas = 0;

    for (int i = 1; i < int(vetor.size() - 1); i++) {
        if (abs(vetor[i]) > 50 && abs(vetor[i - 1]) > 30 && abs(vetor[i + 1]) > 30)
            quantidade_brigas++;
    }
    
    return quantidade_brigas;
}

vector<int> apaziguado(const vector<int>& vetor) 
{
    vector<int> posicoes_apaziguados {};

    for (int i = 0; i < int(vetor.size()); i++) {
        if (i == 0) {
            if (abs(vetor[i]) > 80 && abs(vetor[i + 1]) < 10) {
                posicoes_apaziguados.push_back(i);
            }
        } else if (i == int(vetor.size() - 1)) {
            if (abs(vetor[i]) > 80 && abs(vetor[i - 1]) < 10) {
                posicoes_apaziguados.push_back(i);
            }
        } else {
            if (abs(vetor[i]) > 80 && (abs(vetor[i - 1]) < 10 || abs(vetor[i + 1]) < 10)) {
                posicoes_apaziguados.push_back(i);
            }
        }
    }

    return posicoes_apaziguados;
}