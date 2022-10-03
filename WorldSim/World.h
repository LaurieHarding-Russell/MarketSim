#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include <string>
#include <time.h> 
#include <random>
#include <iostream>

#include <map>

#include "Capitalism/Company.h"
#include "Capitalism/Investor.h"
#include "Capitalism/Stock.h"
#include "NameGenerator.h"
#include "Map/Map.h"
#include "Map/Coordinate.h"

class World {
    public:
        World();
        Investor registerTradingBot(std::string name);


        // None trading api
        void reset();
        void simulateYear();
        int getYear();

    private:
        std::default_random_engine generator;
        std::vector<Company> companies; // FIXME, should probably be a set.
        std::vector<Investor> investors;

        int year;
        Map worldMap;
        std::map<std::string, Stock> stocks;
        
        void generateMap();
        Company generateRandomCompany();
};

#endif