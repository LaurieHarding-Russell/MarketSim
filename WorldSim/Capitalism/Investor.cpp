#include "Investor.h"

Investor::Investor(std::string name) {
    // FIXME, think about this
    this->name = name;
    this->funds = 1000.00;
}

double Investor::getFunds() {
    return funds;
}

std::string Investor::getName() {
    return name;
}