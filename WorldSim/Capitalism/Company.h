#ifndef COMPANY_H
#define COMPANY_H

#include <string>

#include "../Humanity/Person.h"

#include "single_include/nlohmann/json.hpp"

using json = nlohmann::json;

class Company {
    public:
    Company(std::string name);
    std::string getName();
    
    Company* setFunds(double funds);

    friend void to_json(json& j, const Company& investor);
    friend void from_json(const json& j, Company& investor);

    private:
        std::string name;
        Person employees;
        double funds;
        
};

#endif