#pragma once
#include <iostream>
#include <vector>

using namespace std;

int sexo(const int& elemento)
{
    if (elemento > 0)
        return 1;
    else
        return -1;
}

int quantos_times(const vector<int>& vetor) 
{
    int sexo_atual = sexo(vetor[0]), times = 0, pessoas = 0;

    for (int i = 0; i < int(vetor.size()); i++) {
        if (sexo(vetor[i]) == sexo_atual) {
            pessoas++;
        } else {
            if (pessoas >= 2) {
                times++;
            }
            
            sexo_atual = sexo(vetor[i]);
            pessoas = 1;
        }
    }

    if (pessoas >= 2) {
        times++;
    }
    
    return times;
}

vector<int> maior_time(const vector<int>& vetor) 
{
    int sexo_atual = sexo(vetor[0]), times = 0, pessoas = 0;
    vector<int> time_atual {}, time_maior {};

    for (int i = 0; i < int(vetor.size()); i++) {
        if (sexo(vetor[i]) == sexo_atual) {
            pessoas++;
            time_atual.push_back(vetor[i]);
        } else {
            if (pessoas >= 2) {
                times++;
                if (time_maior.size() < time_atual.size()) time_maior = time_atual;
            }
            
            time_atual.clear();
            sexo_atual = sexo(vetor[i]);
            pessoas = 1;
            time_atual.push_back(vetor[i]);
        }
    }

    if (pessoas >= 2) {
        times++;
        if (time_maior.size() < time_atual.size()) time_maior = time_atual;
    }
    
    return time_maior;
}

int pessoas_sem_time(const vector<int>& vetor)
{
    int sexo_atual = sexo(vetor[0]), pessoas_sos= 0, pessoas = 0;

    for (int i = 0; i < int(vetor.size()); i++) {
        if (sexo(vetor[i]) == sexo_atual) {
            pessoas++;
        } else {
            if (pessoas < 2) {
                pessoas_sos++;
            }
            
            sexo_atual = sexo(vetor[i]);
            pessoas = 1;
        }
    }

    if (pessoas < 2) {
        pessoas_sos++;
    }
    
    return pessoas_sos;
}