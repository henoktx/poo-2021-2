#include <iostream>
#include <vector>
#include "include/funcionalidades.hpp"
#include "include/busca.hpp"
#include "include/contagem.hpp"
#include "include/melhor-caso.hpp"

using namespace std;

int main() 
{
    cout.setf(ios::boolalpha);

    int tamanho {}, desejado {}, ponto_origem {};

    cout << "Digite o tamanho: ";
    cin >> tamanho;

    vector<int> vetor_entrada(tamanho);

    preenche_vetor(vetor_entrada);
   
    cout << "Valor desejado: ";
    cin >> desejado;

    cout << endl;

    cout << "Existe: " << existe(vetor_entrada, desejado) << endl;
    cout << "Contar: " << contar(vetor_entrada, desejado) << endl; 
    cout << "Posição do valor " << desejado << ": " << procular_valor(vetor_entrada, desejado) << endl;  

    cout << "Buscar a partir da posição: ";
    cin >> ponto_origem;
    cout << "Procurar a partir: " << procura_valor_apos(vetor_entrada, desejado, ponto_origem) << endl;

    cout << endl;

    cout << "Stress medio: " << calcular_stress_medio(vetor_entrada) << endl;
    cout << "Mais homens ou mulheres: " << mais_homens_ou_mulheres(vetor_entrada) << endl;
    cout << "Qual metade mais estressada: " << qual_metade_eh_mais_estressada(vetor_entrada) << endl;
    cout << "Homens são mais estressados que mulheres: " << homens_sao_mais_estressados_que_mulheres(vetor_entrada) << endl;

    cout << endl;

    cout << "Procurar menor: " << procurar_menor(vetor_entrada) << endl;
    cout << "Procurar menor após: " << procurar_menor_pos(vetor_entrada) << endl;
    
    cout << "Buscar a partir da posição: ";
    cin >> ponto_origem;
    cout << "Procurar menor a partir: " << procurar_menor_pos_apartir(vetor_entrada, ponto_origem) << endl;
    cout << "Procurar melhor se: " << procurar_melhor_se(vetor_entrada) << endl;

    return 0;
}