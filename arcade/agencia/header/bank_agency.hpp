#pragma once

#include "client.hpp"
#include "saving_account.hpp"
#include "checking_account.hpp"
#include <map>
#include <memory>

class Bank_agency {
private:
    std::map<int, std::shared_ptr<Account>> accounts;
    std::map<std::string, Client> clients;
    int next_account {0};
    std::string nome;

public:
    Bank_agency(const std::string &nome) {
        this->nome = nome;
        std::cout << "Banco " << nome << " criado" << std::endl;
    }

    void add_client(const std::string &client_id) {
        Client cliente(client_id);

        auto conta1 = std::make_shared<Checking_account>(client_id, next_account++);
        auto conta2 = std::make_shared<Saving_account>(client_id, next_account++);
        
        accounts.insert(std::make_pair(conta1->get_id(), conta1));
        accounts.insert(std::make_pair(conta2->get_id(), conta2));

        cliente.add_account(std::static_pointer_cast<Account>(conta1));
        cliente.add_account(std::static_pointer_cast<Account>(conta2));

        clients.insert(std::make_pair(client_id, cliente));

        std::cout << "Cliente " << client_id << " foi adicionado com suas contas" << std::endl;
    }

    void deposity(const int id, float value) {
        if (accounts.count(id) == 0) {
            std::cout << "ID não existente" << std::endl;
            return;
        }
        accounts[id]->deposite(value);
    }

    void monthly_update() {
        for (auto i : accounts) {
            i.second->monthly_update();
        }
        std::cout << "Contas atualizadas" << std::endl;
    }

    void transfer(int contde, int contpara, float value) {
        accounts[contde]->transfer(*accounts[contpara], value);
    }

    void withdraw(int id, float value) {
        accounts[id]->withdraw(value);
    }

    std::string to_string() {
        std::stringstream ss;
        for (auto i : clients) {
            ss << i.second.to_string() << std::endl;
        }
        ss << std::endl;
        for (auto j : accounts) {
            ss << j.second->to_string() << (j.second->get_id() == (--accounts.end())->second->get_id() ? "" : "\n");
        }
        return ss.str();
    }
};