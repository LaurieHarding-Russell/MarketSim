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
    
    generateMap();
    generatePeople();
    generateCompanies();
}

void World::simulateYear() {
    year = year + 1;
    // Companies fire
    for (auto &companyPair : companies) {
        Company company = companyPair.second;
        company.evaluateCeo();
        company.removePervicedWorstEmployees();
        company.hireBestPercivedBestEmployees(
            getUnemployedPeopleWithinTravelingDistance(company.getCoordinate())
        );
        company.paySalaries();
        company.buyUpgrades();
        company.produce();
    }

    for (auto &person : people) {
        if (!person.isFed() && person.getFunds() > 1) {
            // FIXME, amount to feed dependent on person perhaps?
            std::optional<Company> foodStore = getClosestBusinessThatSellsX(person, FOOD, 1);
            if (foodStore.has_value()) {
                Company store = foodStore.value_or(Company());
                store.sellProduces(1);
                person.adjustFunds(-1);
            }
        }

        if (person.canProduceKid() && birthrateDistribution(generator) == 1) {
            // TODO, setup the kid to succeed... and uh multiple parents?
            people.push_back(
                Consumer(ConsumerUtil::generateKid(person, person))
            );
        }
    }
    for (int i = people.size() - 1; i != 0; i--) {
        if (!people.at(i).isAlive()) {
            people.erase(people.begin() + i);
        }
    }
    // Remove dead companies
}

int World::getYear() {
    return year;
}

Company World::getCompany(std::string name) {
    return companies.find(name)->first;
}

std::vector<Company> World::getCompanies() {
    std::vector<Company> companyList = std::vector<Company>();
    for (auto &company : companies) {
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

    std::uniform_int_distribution<int> productTypeDistribution(0, 4);
    company.setProductType(ALL_PRODUCTS.at(productTypeDistribution(generator)));

    company.setFunds(fundsDistribution(generator));
    company.setCoordinate(worldMap.getValidCoordinate());
    return company;
}

void World::generateMap() {
    worldMap = Map(
        Coordinate().setX(0.0).setY(0.0),
        Coordinate().setX(100.0).setY(100.0)
    );
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

std::vector<Consumer> World::getUnemployedPeople() {
    std::vector<Consumer> unemployed = std::vector<Consumer>();
    for (auto &person : people) {
        if (person.getWork() == "") {
            unemployed.push_back(person);
        }
    }
    return unemployed;
}

std::vector<Consumer> World::getUnemployedPeopleWithinTravelingDistance(Coordinate coordinate) {
    std::vector<Consumer> employable = std::vector<Consumer>();
    std::vector<Consumer> unemployed = getUnemployedPeople();
    
    for (auto &person : unemployed) {
        if (person.canTravelTo(coordinate)) {
            employable.push_back(person);
        }
    }
    return employable;
}

// TODO, find all and get closest. Might add prices of products at some point. Think about amount
std::optional<Company> World::getClosestBusinessThatSellsX(Consumer person, ProductType type, double amount) {
    
    for (auto &companyPair : companies) {
        if (person.canTravelTo(companyPair.second.getCoordinate()) &&
            companyPair.second.canSellProduct(type, amount)
        ) {
            return companyPair.second;
        }
    }
    return std::nullopt;
}