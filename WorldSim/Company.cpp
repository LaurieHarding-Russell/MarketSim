#include "Company.h"

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

void to_json(json& j, const Company& company) {
    j = json{
        {"name", company.name}, 
        {"funds", company.funds}
    };
}

void from_json(const json& j, Company& company) {
    j.at("name").get_to(company.name);
    j.at("funds").get_to(company.funds);
}