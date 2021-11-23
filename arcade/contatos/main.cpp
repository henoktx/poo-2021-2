#include "contato.hpp"

int main() {
    std::list<std::shared_ptr<Fone>> dois;
    dois.push_back(std::make_shared<Fone>("oi", "42312"));
    
    Contato um("henok", dois);
    um.addFone(std::make_shared<Fone>("tim", "42212"));

    std::cout << um.toString() << std::endl;

    um.setName("hugo");
    
    std::cout << um.toString() << std::endl;

    return 0;
}