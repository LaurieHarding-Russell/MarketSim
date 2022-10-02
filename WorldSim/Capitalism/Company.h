#ifndef COMPANY_H
#define COMPANY_H

#include <string>

#include "../Humanity/Person.h"
#include "../Humanity/Building.h"

#include "../Deserializable/Deserializable.h"

using json = nlohmann::json;


// Might want business to have multiple locations. Keeping it simple for now.
class Company: public Building {
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