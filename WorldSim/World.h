#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include <unordered_set>
#include <boost/functional/hash/hash.hpp>

#include <string>
#include <time.h> 
#include <random>
#include <iostream>

#include <map>
#include <optional>

#include "Capitalism/Company.h"
#include "Capitalism/Investor.h"
#include "Capitalism/Stock.h"
#include "Capitalism/Consumer.h"
#include "NameGenerator.h"
#include "Map/Map.h"
#include "Map/Coordinate.h"

class World {
    public:
        World();
        Investor registerTradingBot(std::string name);
        Company getCompany(std::string name);

        std::vector<Company> getCompanies();
        std::vector<Consumer> getPeople();
        std::vector<Investor> getInvestors();

        // None trading api
        void reset();
        void simulateYear();
        int getYear();

    private:
        std::default_random_engine generator;
        std::map<std::string, Company> companies;
        std::vector<Consumer> people;
        std::vector<Investor> investors;

        std::uniform_int_distribution<int> birthrateDistribution; 

        int year;
        Map worldMap;
        std::map<std::string, Stock> stocks;
        
        void generateMap();
        void generateCompanies();
        void generatePeople();

        std::vector<Consumer> getUnemployedPeople();
        std::vector<Consumer> getUnemployedPeopleWithinTravelingDistance(Coordinate coordinate);

        std::optional<Company> getClosestBusinessThatSellsX(Consumer person, ProductType type, double amount);
    
        Company generateRandomCompany();
        Consumer generateRandomPerson();

};

#endif