#pragma once
#include <iostream>
#include <vector>

using namespace std;

void preenche_vetor(vector<int>& vetor) 
{
    for (int i = 0; i < int(vetor.size()); i++) {
        cin >> vetor[i];
    }
}

ostream& operator<<(ostream& os, const vector<int>& v) 
{
    os << "[ ";
    for (auto i : v)
        os << i << " ";
    os << "]";
    
    return os;
}