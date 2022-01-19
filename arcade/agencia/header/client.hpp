#pragma once

#include "account.hpp"
#include <list>
#include <memory>

class Client {
private:
    std::list<std::shared_ptr<Account>> contas;
    std::string client_id;

public:
    Client(const std::string &client_id) : client_id(client_id) {}

    void add_account(std::shared_ptr<Account> conta) {this->contas.push_back(conta);}

    std::string to_string() {
        std::stringstream ss;
        ss << "- " << this->client_id << " ["; 
        for (auto i : this->contas) {
            ss << i->get_id() << (i->get_id() != contas.back()->get_id() ? ", " : "");
        }
        ss << "]";
        return ss.str();
    }

    void set_accounts(const std::list<std::shared_ptr<Account>> &contas) {this->contas = contas;}

    void set_client_id(const std::string &client_id) {this->client_id = client_id;}

    std::list<std::shared_ptr<Account>> get_accounts() {return this->contas;}

    std::string get_client_id() {return this->client_id;}
};