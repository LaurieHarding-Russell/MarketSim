#ifndef CONSUMER_H
#define CONSUMER_H

#include "Company.h"

class Consumer: public Person {
    public:
    int getFunds();
    int adjustFunds(int amount);
    bool canRemoveFunds(int amount);

    private:
    int funds;

    
};

#endif