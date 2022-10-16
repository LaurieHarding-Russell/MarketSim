#ifndef COMPANY_H
#define COMPANY_H

#include <string>

#include "../Humanity/Person.h"
#include "../Humanity/Building.h"


// Might want business to have multiple locations. Keeping it simple for now.
class Company: public Building {
    public:
    Company();
    Company(std::string name);
    std::string getName();
    
    Company* setFunds(double funds);
    double getFunds();

    private:
        std::string name;
        Person employees;
        double funds;
        
};

#endif