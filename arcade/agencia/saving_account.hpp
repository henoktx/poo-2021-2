#include "account.hpp"

class Saving_account : public Account {
public:
    Saving_account(const std::string &client_id, const int id) : 
    Account(client_id, id) {this->type = "CP";}

    void monthly_update() override {
        if (this->balance <= 0) {
            return;
        }
        this->balance *= 1.01;
    }
};