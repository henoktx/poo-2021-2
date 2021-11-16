#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include "cinema.hpp"

std::ostream& operator<<(std::ostream& os, const std::vector<std::shared_ptr<Pessoa>>& cinema) {
    for (int i = 0; i < (int) cinema.size(); i++) {
        if (cinema.at(i) == nullptr) {
            os << "Cadeira " << i << " -> [vazia] | ";
            continue;
        } else {
            os << "Cadeira " << i << " -> " << cinema.at(i)->getNome() << " | ";
        }
    }

    return os;
}