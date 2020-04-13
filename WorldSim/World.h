#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include <string>
#include <time.h> 

#include "single_include/nlohmann/json.hpp"

#include <map>

#include "Company.h"
#include "Investor.h"
#include "Stock.h"
#include "NameGenerator.h"

using json = nlohmann::json;

class World {
    public:
        std::string getStockmarketData();
        std::string registerTradingBot(std::string name);
        std::string registerTradingBot(std::string name, std::string host, std::string port);


        // None trading api
        std::string reset();
        std::string simulateYear();
        int getYear();

    private:
        std::vector<Company> companies;
        std::vector<Investor> investors;
        int year;
        std::map<std::string, Stock> stocks;

        void generateCompanies();
        Company generateRandomCompany();
        json asJson();
};

#endif