#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include <string>
#include <time.h> 
#include <random>

#include <map>

#include "Capitalism/Company.h"
#include "Capitalism/Investor.h"
#include "Capitalism/Stock.h"
#include "NameGenerator.h"
#include "Map/Map.h"
#include "Map/Coordinate.h"
#include "Deserializable/Deserializable.h"

using json = nlohmann::json;

class World: public Deserializable{
    public:
        World();
        std::string getStockmarketData();
        std::string registerTradingBot(std::string name);
        std::string registerTradingBot(std::string name, std::string host, std::string port);


        // None trading api
        std::string reset();
        std::string simulateYear();
        int getYear();

    private:
        std::default_random_engine generator;
        std::vector<Company> companies;
        std::vector<Investor> investors;

        int year;
        Map worldMap;
        std::map<std::string, Stock> stocks;
        
        void generateMap();
        Company generateRandomCompany();
        json asJson();
};

#endif