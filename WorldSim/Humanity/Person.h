#ifndef PERSON_H
#define PERSON_H

#include "../Map/Resource.h"

class Person: public Resource {
    private:
    Coordinate coordinate;
    bool fed; // Have they eaten this turn? They will die if they haven't
    int happy; // will buy entertainment.
    int health;

    public: 
    std::string getType();
    Coordinate getCoordinate();
    
    bool wantToEat();
    void feed();
    bool wantToBeEntertain();
    bool timeToDie();
    void simulateTurn();
};

#endif