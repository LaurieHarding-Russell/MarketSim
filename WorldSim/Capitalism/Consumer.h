#ifndef CONSUMER_H
#define CONSUMER_H

#include "Company.h"
#include "../Deserializable/Deserializable.h"

using json = nlohmann::json;

class Consumer: public Person/*, public Deserializable */ {
    public:
    int getFunds();
    int adjustFunds(int amount);
    bool canRemoveFunds(int amount);

    private:
    int funds;

    
};

#endif