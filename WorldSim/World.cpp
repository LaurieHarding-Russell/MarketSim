#include "World.h"

// Public

World::World() {
    generator = std::default_random_engine(std::random_device{}());
    birthrateDistribution = std::uniform_int_distribution<int>(1, 100);
    reset();
}

void World::reset() {

    year = 0;
    companies.clear();
    investors.clear();
    
    generatePeople();
    generateMap();
}

void World::simulateYear() {
    year = year + 1;
    // Companies employ

    // Companies produce stuff.

    // People consume stuff.

    // People die.

    // People are created.
}

int World::getYear() {
    return year;
}

Company World::getCompany(std::string name) {
    return companies.find(name)->first;
}

std::vector<Company> World::getCompanies() {
    std::vector<Company> companyList = std::vector<Company>();
    for (const auto &company : companies) {
        companyList.push_back( company.second );
    }
    return companyList;
}

std::vector<Consumer> World::getPeople() {
    return people;
}

std::vector<Investor> World::getInvestors() {
    return investors;
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
        if (companies.count(newCompanyName)) {
            unique = false;
        }
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
    generateCompanies();
}


void World::generateCompanies() {
    std::uniform_int_distribution<int> numberOfCompaniesDistribution(25, 125);

    int numberOfCompanies = numberOfCompaniesDistribution(generator);

    for (int i = 0; i != numberOfCompanies; i++) {
        Company company = generateRandomCompany();
        companies[company.getName()] = company;
    }
}

void World::generatePeople() {
    std::uniform_int_distribution<int> numberOfCompaniesDistribution(500, 5000);

    int numberOfPeople = numberOfCompaniesDistribution(generator);

    for (int i = 0; i != numberOfPeople; i++) {
        Consumer person = generateRandomPerson();
        people.push_back(person);
    }
}

Consumer World::generateRandomPerson() {
    std::uniform_int_distribution<int> ageDistribution(1, 80);
    std::uniform_int_distribution<int> healthDistribution(1, 80);
    std::uniform_int_distribution<int> educationDistribution(1, 80);
    std::uniform_int_distribution<int> boolDistribution(0, 1);
    std::uniform_int_distribution<int> happyDistribution(0, 100);
    std::uniform_int_distribution<int> intelligenceDistribution(0, 100);

    Consumer::ConsumerFactory personFactory = Consumer::ConsumerFactory();
    personFactory.age = ageDistribution(generator);
    personFactory.health = healthDistribution(generator);
    personFactory.education = educationDistribution(generator);
    personFactory.fed = boolDistribution(generator);
    personFactory.happy = happyDistribution(generator);
    personFactory.intelligence = intelligenceDistribution(generator);
    personFactory.sex = boolDistribution(generator);

    personFactory.coordinate = worldMap.getValidCoordinate();

    return personFactory.generateConsumer();
}