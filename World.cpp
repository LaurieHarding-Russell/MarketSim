#include "World.h"

// Public
std::string World::reset() {
    companies.clear();
    return getStockmarketData();
}

std::string World::getStockmarketData() {
    return asJson().dump();
}

std::string World::simulateYear() {
    return getStockmarketData();
}


// Private
json World::asJson() {
    json json = json::object();
    return json;
}