#include "carro.hpp"
#include "aviao.hpp"

int main() {
    int escolha {};
    std::cout << "Qual transporte você deseja? 1 - carro | 2 - avião" << std::endl;
    std::cin >> escolha;
    
    Carro uno(1.4, 4, 3);
    Aviao boeing(2, "Rio de janeiro", 30, 100, 100);

    switch (escolha)
    {
    case 1:
        uno.liga_ar_condicionado();
        uno.liga_farol();
        uno.locomover();
        uno.drift();
        uno.usa_step();
        uno.acidente();
        uno.mecanico(1.4);
        uno.locomover();
        uno.abastecer(2);
        uno.locomover();

        std::cout << "\n";

        std::cout << uno.to_string() << std::endl;
        break;
    
    case 2:
        boeing.voar();
        boeing.pousar();
        boeing.voar();
        boeing.acidente();
        boeing.mecanico(30, 1);
        boeing.abastecer(50);
        boeing.voar();

        std::cout << "\n" << boeing.to_string() << std::endl;
    default:
        break;
    }
    
    
    
    return 0;
}