#ifndef INVESTOR_H
#define INVESTOR_H

#include <string>
#include <vector>

#include "Stock.h"


class Investor {
    public:
    Investor(std::string name);
    double getFunds();
    std::string getName();

    private:

    std::string name;
    double funds;

    std::string url;

    std::vector<Stock> stock;
};

#endif