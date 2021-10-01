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

int main() 
{
    cout << existe({-1, -50, -99}, -1) << endl; // 1
    cout << existe({-1, -50, -99}, 10) << endl; // 0

    cout << endl;
    
    cout << contar({-1, -50, -1, -99}, -1) << endl; // 2
    cout << contar({-1, -50, -1, -99}, 10) << endl; // 0

    cout << endl;

    cout << procular_valor({-1, -50, -1, -99}, -99) << endl; // 3
    cout << procular_valor({-1, -50, -1, -99}, 10) << endl; // -1
    
    cout << endl;

    cout << procura_valor_apos({5, 3, -1, -50, -1, -99}, -1, 0) << endl; // 2
    cout << procura_valor_apos({5, 3, -1, -50, -1, -99}, -1, 3) << endl; // 4
    cout << procura_valor_apos({5, 3, -1, -50, -1, -99}, -1, 4) << endl; // 4

    return 0;
}