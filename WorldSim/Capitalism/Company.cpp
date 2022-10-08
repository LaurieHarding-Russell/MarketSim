#include "Company.h"

Company::Company() {

}

Company::Company(std::string name) {
    this->name = name;

}

std::string Company::getName() {
    return name;
}

Company* Company::setFunds(double funds) {
    this->funds = funds;
    return this;
}