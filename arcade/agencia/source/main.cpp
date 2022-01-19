#include "../header/bank_agency.hpp"

int main() {
    Bank_agency banco("Nubank");

    std::cout << std::endl;

    banco.add_client("Hugo");
    banco.add_client("Henok");

    std::cout << std::endl;

    std::cout << banco.to_string() << std::endl;

    std::cout << std::endl;

    banco.deposity(3, 1000);
    banco.deposity(1, 2000);

    std::cout << std::endl;

    banco.monthly_update();

    std::cout << std::endl;

    std::cout << banco.to_string() << std::endl;

    std::cout << std::endl;

    banco.transfer(3, 1, 2000);

    std::cout << std::endl;

    banco.withdraw(3, 1000);

    std::cout << std::endl;

    banco.monthly_update();
    
    std::cout << std::endl;

    std::cout << banco.to_string() << std::endl;

    return 0;
}