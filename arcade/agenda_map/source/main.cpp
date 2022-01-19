#include "../header/agenda.hpp"

int main() {
    std::list<std::shared_ptr<Fone>> dois;
    dois.push_back(std::make_shared<Fone>("oi", "42312"));
    
    std::list<std::shared_ptr<Fone>> tres;
    tres.push_back(std::make_shared<Fone>("oi", "412442"));
    
    auto c1 = std::make_shared<Contato>("henok", dois);
    c1->addFone(std::make_shared<Fone>("tim", "42212"));

    auto c2 = std::make_shared<Contato>("hugo", tres);

    auto c3 = std::make_shared<Contato>("ana", tres);
    auto c4 = std::make_shared<Contato>("alice barbosa", tres);
    auto c5 = std::make_shared<Contato>("alice almeida", tres);
    auto c6 = std::make_shared<Contato>("zilda", tres);
    auto c7 = std::make_shared<Contato>("julia", tres);

    Agenda agenda1;

    std::cout << std::endl;

    agenda1.addContato(c1);
    agenda1.addContato(c2);
    agenda1.addContato(c3);
    agenda1.addContato(c4);
    agenda1.addContato(c5);
    agenda1.addContato(c6);
    agenda1.addContato(c7);

    std::cout << std::endl;

    agenda1.procura("h");
    std::cout << std::endl;
    
    agenda1.getContato("h");
    std::cout << std::endl;

    agenda1.rmContato("hugo");
    std::cout << std::endl;

    agenda1.getContato("hugo");
    std::cout << std::endl;

    agenda1.rmContato("henok");
    std::cout << std::endl;

    agenda1.procura("t");
    std::cout << std::endl;

    std::cout << agenda1.toString() << std::endl;
}