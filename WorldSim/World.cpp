#include "World.h"

// Public

World::World() {
    generator = std::default_random_engine(std::random_device{}());
    reset();
}

void World::reset() {

    year = 0;
    companies.clear();
    investors.clear();
    
    generateMap();
}

void World::simulateYear() {
    year = year + 1;
}

int World::getYear() {
    return year;
}

Company World::getCompany(std::string name) {
    return companies.find(name)->first;
}

std::vector<Company> World::getCompanies() {
    // for( MapType::iterator it = m.begin(); it != m.end(); ++it ) {
    //     v.push_back( it->second );
    // }
    return std::vector<Company>();
}

// FIXME, do I want to do anything special if no callback url exists?
Investor World::registerTradingBot(std::string name) {
    Investor investor = Investor(name); 
    investors.push_back(investor);
    return investor;
}

Company World::generateRandomCompany() {
    std::string newCompanyName = "";
    bool unique;
    do {
        newCompanyName = nameGenerator::corporateNameGenerator();
        unique = true;
        // for (Company company: companies) {
        if (companies.find(newCompanyName) == companies.end()) {
            unique = false;
        }
        // }
    } while(!unique);
    Company company = Company(newCompanyName);
    std::uniform_int_distribution<int> fundsDistribution(0, 1000);
    company.setFunds(fundsDistribution(generator));
    company.setCoordinate(worldMap.getValidCoordinate());
    return company;
}

void World::generateMap() {
    worldMap = Map(
        Coordinate().setX(0.0).setY(0.0),
        Coordinate().setX(100.0).setY(100.0)
    );    
    std::uniform_int_distribution<int> numberOfCompaniesDistribution(25, 125);

    int numberOfCompanies = numberOfCompaniesDistribution(generator);

    for (int i = 0; i != 25; i++) {
        Company company = generateRandomCompany();
        companies[company.getName()] = company;
    }
}
