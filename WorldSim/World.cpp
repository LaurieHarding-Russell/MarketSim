#include "World.h"

// Public

World::World() {
    generator = std::default_random_engine(std::random_device{}());
    reset();
}

std::string World::reset() {

    year = 0;
    companies.clear();
    investors.clear();
    
    generateMap();
     
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
    std::uniform_int_distribution<int> fundsDistribution(0, 1000);
    company.setFunds(fundsDistribution(generator));
    return company;
}

void World::generateMap() {
    this->worldMap = Map(
        Coordinate().setX(0.0).setY(0.0),
        Coordinate().setX(100.0).setY(100.0)
    );
    
    std::uniform_int_distribution<int> numberOfCompaniesDistribution(25, 125);


    int numberOfCompanies = numberOfCompaniesDistribution(generator);

    for (int i = 0; i != numberOfCompanies; i++) {
        companies.push_back(generateRandomCompany());
    }


}
