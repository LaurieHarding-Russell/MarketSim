#include "World.h"

// Public

std::string World::reset() {
    srand (time(NULL));

    year = 0;
    companies.clear();
    investors.clear();
    
    generateCompanies();
    
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
    return json {
        {"investor", investor}
    }.dump();
}

// ***** Private *****
json World::asJson() {
    return json {
        {"year", year}, 
        {"investor", investors},
        {"companies", companies}
    };
}

void World::generateCompanies() {
    int numberOfCompanies = rand() % 100 + 25;
    for (int i = 0; i != numberOfCompanies; i++) {
        companies.push_back(generateRandomCompany());
    }
}

Company World::generateRandomCompany() {
    std::string newCompanyName = "";
    bool unique;
    do {
        newCompanyName = nameGenerator::corporateNameGenerator();
        unique = true;
        for (auto company: companies) {
            if (company.getName() == newCompanyName) {
                unique = false;
                break;
            }
        }
    } while(!unique);
    Company company = Company(newCompanyName);
    company.setFunds(rand() % 1000);
    return company;
}