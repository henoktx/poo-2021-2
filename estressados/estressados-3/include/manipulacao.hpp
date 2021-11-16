#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> sozinhos(const vector<int>& vetor) 
{
    vector<int> vetor_copy {vetor}, selecionados {};

    for (int i = 0; i < int(vetor_copy.size()) ; i++) {
        if (vetor_copy[i] < 0)
            vetor_copy[i] *= (-1);
    }

    for (int j = 0; j < int (vetor_copy.size()) ; j++) {
        if (count(vetor_copy.begin(), vetor_copy.end(), vetor[j]) == 1)
            selecionados.push_back(vetor_copy[j]);
    }

    return selecionados;
}

int mais_ocorrencias(const vector<int>& vetor)
{
    int maior_ocorrencia {};

    for (int i = 0; i < int(vetor.size()); i ++){
        int ocorrencias = 0;
        for (int j = 0; j < int(vetor.size()); j ++) {
            if (abs(vetor[i]) == abs(vetor[j]))
                ocorrencias++;
        }

        if (ocorrencias > maior_ocorrencia)
            maior_ocorrencia = ocorrencias;
    }

    return maior_ocorrencia;
}

vector<int> mais_recorrentes(const vector<int>& vetor)
{
    vector<int> vetor_copy {vetor}, recorrentes {};
    
    for (int i = 0; i < int(vetor_copy.size()) ; i++) {
        if (vetor_copy[i] < 0)
            vetor_copy[i] *= (-1);
    }
    
    int ocorrencias = mais_ocorrencias(vetor_copy);

    for (int i = 0; i < int(vetor_copy.size()); i ++) {
        if (count(vetor_copy.begin(), vetor_copy.end(), vetor_copy[i]) == ocorrencias)
            if (find(recorrentes.begin(), recorrentes.end(), vetor_copy[i]) == recorrentes.end())
                recorrentes.push_back(vetor_copy[i]);
    }       

    return recorrentes;
}