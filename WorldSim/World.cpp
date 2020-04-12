#include "World.h"

#include <iostream>
// Public

std::string World::reset() {
    year = 0;
    companies.clear();
    investors.clear();
    return getStockmarketData();
}

std::string World::getStockmarketData() {
    return asJson().dump();
}

std::string World::simulateYear() {
    year = year + 1;
    return getStockmarketData();
}

int World::getYear() {
    return year;
}

// FIXME, do I want to do anything special if no callback url exists?
std::string World::registerTradingBot(std::string name) {
    return registerTradingBot(name, "", "");
}

std::string World::registerTradingBot(std::string name, std::string host, std::string port) {
    Investor investor = Investor(name, host, port); 
    investors.push_back(investor);
    return "{}";
}

// ***** Private *****
json World::asJson() {
    return json {
        {"year", year}, 
        {"investor", investors}
    };
}