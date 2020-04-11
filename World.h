#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include <string>

#include "single_include/nlohmann/json.hpp"

#include "Company.h"

using json = nlohmann::json;

class World {
    public:
        std::string reset();
        std::string getStockmarketData();
        std::string simulateYear();

    private:
        
        std::vector<Company> companies;
        json asJson();

};

#endif