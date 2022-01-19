#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include "cinema.hpp"

std::ostream& operator<<(std::ostream& os, const std::map<int,std::shared_ptr<Pessoa>>& cinema) {
    for (auto i : cinema)  { 
        os << "Cadeira " << i.first << " -> " << i.second << " | ";
    }
        return os;
}