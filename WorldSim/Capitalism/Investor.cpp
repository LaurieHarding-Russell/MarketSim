#include "Investor.h"

Investor::Investor(std::string name) {
    // FIXME, think about this
    Investor(name, "", "");
}

Investor::Investor(std::string name, std::string host, std::string port) {
    this->name = name;
}

double Investor::getFunds() {
    return funds;
}

std::string Investor::getName() {
    return name;
}