#pragma once

#include "account.hpp"

class Checking_account : public Account {
public:
    Checking_account(const std::string &client_id, const int id) :
    Account(client_id, id) {this->type = "CC";}

    void monthly_update() override {this->balance -= 20;}
};