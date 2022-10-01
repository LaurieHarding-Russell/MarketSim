#ifndef STOCK_H
#define STOCK_H

#include "Company.h"

#include "single_include/nlohmann/json.hpp"

using json = nlohmann::json;

class Stock {
    public:

    friend void to_json(json& j, const Stock& investor);
    friend void from_json(const json& j, Stock& investor);

    private:
    Company* company;
    double Shares;
};

#endif