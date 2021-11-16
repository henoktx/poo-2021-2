#include <iostream>
#include "include/funcionalidades.hpp"
#include "include/manipulacao.hpp"
#include "include/proximidade.hpp"
#include "include/alteracoes.hpp"
#include "include/grupos.hpp"
#include "include/sequencias.hpp"

using namespace std;

int main() {
    int tamanho {};
    
    cout << "Digite o tamanho: ";
    cin >> tamanho;

    vector<int> vetor(tamanho);

    preenche_vetor(vetor);
    
    cout << endl;
    
    cout << "Representante único do seu nível de stress: " << sozinhos(vetor) << endl;
    cout << "Mais ocorrências: " << mais_ocorrencias(vetor) << endl;
    cout << "Mais recorrentes: " << mais_recorrentes(vetor) << endl;
    
    cout << endl;

    cout << "Quantidade de brigas: " << briga(vetor) << endl;
    cout << "Posição do(s) apaziguado(s): " <<apaziguado(vetor) << endl;
    
    cout << endl;
    
    cout << "Quantidade de times: " << quantos_times(vetor) << endl;
    cout << "Maior time: " << maior_time(vetor) << endl;
    cout << "Pessoas sem time: " << pessoas_sem_time(vetor) << endl;

    cout << endl;
    
    cout << "Quantidade de casais: " << quantidade_casais(vetor) << endl;
    cout << "Quantidade de trios: " << quantidade_trios(vetor) << endl;

    cout << endl;

    int pessoa_remover {}, pessoa_inserir {}, posicao_inserir {};
    
    cout << "Pessoa a remover: ";
    cin >> pessoa_remover;
    cout << remove(vetor, pessoa_remover) << endl;

    cout << "Pessoa a inserir e sua posição: ";
    cin >> pessoa_inserir >> posicao_inserir;
    cout << insert(vetor, pessoa_inserir, posicao_inserir) << endl;
    
    cout << "Dance: " << dance(vetor) << endl;


    return 0;
}