#pragma once
#include <iostream>
#include <vector>

using namespace std;

vector<int> clone(const vector<int>& vetor_inicial)
{
    vector<int> clone {vetor_inicial};
    
    return clone;
}

vector<int> pegar_homens(const vector<int>& vetor_inicial)
{
    vector<int> so_homens {};

    for (int i = 0; i < int(vetor_inicial.size()); i++) {
        if (vetor_inicial[i] > 0)
            so_homens.push_back(vetor_inicial[i]);
    }

    return so_homens;
}

vector<int> pegar_calmos(const vector<int>& vetor_inicial)
{
    vector<int> so_calmos {};

    for (int i = 0; i < int(vetor_inicial.size()); i++) {
        if (vetor_inicial[i] > -10 && vetor_inicial[i] < 10) {
            so_calmos.push_back(vetor_inicial[i]);
        }
    }

    return so_calmos;
}

vector<int> pegar_mulheres_calmas(const vector<int>& vetor_inicial)
{
    vector<int> so_calmas {};

    for (int i = 0; i < int(vetor_inicial.size()); i++) {
        if (vetor_inicial[i] > -10 && vetor_inicial[i] < 0)
            so_calmas.push_back(vetor_inicial[i]);
    }

    return so_calmas;
}