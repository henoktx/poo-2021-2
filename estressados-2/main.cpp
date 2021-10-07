#include <iostream>
#include <vector>
#include "funcionalidades.hpp"
#include "filter.hpp"
#include "acesso.hpp"
#include "conjuntos.hpp"

using namespace std;

int main () {
    int tamanho {};

    cout << "Digite o tamanho: ";
    cin >> tamanho;

    vector<int> vetor_entrada(tamanho);

    preenche_vetor(vetor_entrada);
    cout << vetor_entrada << endl;
    cout << clone(vetor_entrada) << endl;
    cout << pegar_homens(vetor_entrada) << endl;
    cout << pegar_calmos(vetor_entrada) << endl;
    cout << pegar_mulheres_calmas(vetor_entrada) << endl;

    cout << endl;

    cout << inverter_com_copia(vetor_entrada) << endl;
    inverter_inplace(vetor_entrada);
    cout << vetor_entrada << endl;
    cout << "[ " << sortear(vetor_entrada) << " ]" << endl;
    embaralhar(vetor_entrada);
    cout << vetor_entrada << endl;
    ordenar(vetor_entrada);
    cout << vetor_entrada << endl;

    cout << endl;

    cout << exclusivos(vetor_entrada) << endl;
    cout << diferentes(vetor_entrada) << endl;
    cout << abandonados(vetor_entrada) << endl;

    return 0;
}