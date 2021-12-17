#pragma once

#include <iostream>
#include <sstream>

class Account {
private:
    static bool checa_valor (float value, float balance) {
        if (balance < value) {
            std::cout << "Saldo insuficiente para realizar a operação" << std::endl;
            std::cout << "Saldo: " << balance << " | Valor desejado: " << value << " | Saldo após a transação: " << balance - value << std::endl;
            std::cout << "Deseja prosseguir? Sim [s] | Não [n]" << std::endl;
            if (std::getchar() == 's') {
                std::getchar();
                return true;
            }
            return false;
        } else if (value <= 0) {
            std::cout << "O valor desejado não é válido" << std::endl;
            return false;
        }
        return true;
    }

protected:
    float balance;
    std::string cliente_id;
    int id;
    std::string type;

public:
    Account(const std::string &cliente_id, const int id) :
    balance {}, cliente_id(cliente_id), id(id), type {} {}

    void deposite(const float value) {
        std::cout << "Depósito realizado com sucesso" << std::endl;
        this->balance += value;
    }

    virtual void monthly_update() = 0;

    void transfer(Account &other, const float value) {
        if (!Account::checa_valor(value, this->balance)) return;
        this->balance -= value;
        other.balance += value;
        std::cout << "Transferência realizada com sucesso" << std::endl;
    }

    void withdraw(const float value) {
        if (!Account::checa_valor(value, this->balance)) return;
        this->balance -= value;
        std::cout << "Saque realizado com sucesso" << std::endl;
    }

    float get_balance() {return this->balance;}

    std::string get_client_id() {return this->cliente_id;}

    int get_id() {return this->id;}

    std::string get_type() {return this->type;}

    std::string to_string() {
        std::stringstream ss;
        ss << this->id << ":" << this->cliente_id << ":" << this->balance << ":" << this->type;
        return ss.str();
    }
};