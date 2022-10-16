#include "Company.h"

Company::Company() {
    produces = FOOD;
    equipmentModifier = 1; // FIXME, todo
}

Company::Company(std::string name) {
    this->name = name;
}

bool Company::canSellProduct(ProductType product, double amount) {
    return product == produces && amount < product;
}

double Company::sellProduces(double amount) {
    funds = funds + amount;
    productStored = productStored - amount;
}

std::string Company::getName() {
    return name;
}

Company* Company::setFunds(double funds) {
    this->funds = funds;
    return this;
}

Company* Company::setProductType(ProductType productType) {
    this->produces = productType;
    return this;
}

double Company::getFunds() {
    return funds;
}

Consumer Company::getCeo() {
    return ceo;
}

std::vector<Consumer> Company::getEmployees() {
    return employees;
}

void Company::evaluateCeo() {
    if (!ceo.isAlive()) {
        // TODO: get new CEO from top percieved employee.
    }
}

void Company::removePervicedWorstEmployees() {
    std::sort (employees.begin(), employees.end(), employeeSortOperator);
    // TODO, take into account salary etc fire a few extra to try and rehire.
}
void Company::hireBestPercivedBestEmployees(std::vector<Consumer> unemployed) {
    // TODO: Only higher enough to keep on doing job.
    std::sort (unemployed.begin(), unemployed.end(), employeeSortOperator);
    unemployed.at(0).setWork(name);
}

// FIXME
// bool Company::employeeSortOperator (Consumer i, Consumer j) { 
//     return (i.getPercievedProductivityScore(ceo.getIntelligence()) >
//         j.getPercievedProductivityScore(ceo.getIntelligence())
//     ); 
// }

bool Company::employeeSortOperator (Consumer i, Consumer j) { 
    return (i.getPercievedProductivityScore(50) >
        j.getPercievedProductivityScore(50)
    ); 
}

void Company::paySalaries() {
    for (auto &employee : employees) {
        employee.adjustFunds(calculateEmployeeSalary());
    }
}

void Company::buyUpgrades() {
    // TODO
}

void Company::produce() {
    double totalProduced = 0;
    for (auto &employee : employees) {
        double produces = employee.getProductivityScore() * equipmentModifier;
        double steals = produces * (employee.getIntelligence()/100);
        employee.adjustFunds(steals);
        totalProduced = produces - steals; // FIXME, things will get wierd with +100 coruption and negative production...
    }
    productStored = productStored + totalProduced;
}

double Company::calculateEmployeeSalary() {
    return 1;
}
