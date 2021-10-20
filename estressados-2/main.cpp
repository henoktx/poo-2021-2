#include <iostream>
#include <vector>
#include "include/funcionalidades.hpp"
#include "include/filter.hpp"
#include "include/acesso.hpp"
#include "include/conjuntos.hpp"

using namespace std;

int main () {
    int tamanho {};

    cout << "Digite o tamanho: ";
    cin >> tamanho;

    vector<int> vetor_entrada(tamanho);

    preenche_vetor(vetor_entrada);

    cout << endl;

    cout << vetor_entrada << endl << endl;
    cout << "Vetor clone: " << clone(vetor_entrada) << endl;
    cout << "Pegar homens: " << pegar_homens(vetor_entrada) << endl;
    cout << "Pegar calmos: " << pegar_calmos(vetor_entrada) << endl;
    cout << "Pegar mulheres calmas: " << pegar_mulheres_calmas(vetor_entrada) << endl;

    cout << endl;

    cout << "Inverter com cópia: " << inverter_com_copia(vetor_entrada) << endl;
    inverter_inplace(vetor_entrada);
    cout << "Inverter inplace: " << vetor_entrada << endl;
    cout << "Sortear: [ " << sortear(vetor_entrada) << " ]" << endl;
    embaralhar(vetor_entrada);
    cout << "Embaralhar: " << vetor_entrada << endl;
    ordenar(vetor_entrada);
    cout << "Ordenar: " << vetor_entrada << endl;

    cout << endl;

    cout << "Exclusivos: " << exclusivos(vetor_entrada) << endl;
    cout << "Diferentes: " << diferentes(vetor_entrada) << endl;
    cout << "Abandonados: " << abandonados(vetor_entrada) << endl;

    return 0;
}