#ifndef PERSON_H
#define PERSON_H

#include "../Map/Resource.h"
#include <random>

class Person: public Resource {
    protected:
    Coordinate coordinate;
    bool fed; // Have they eaten this turn? They will die if they haven't
    bool sex;
    int happy; // will buy entertainment.
    int health;
    int education;
    int intelligence;
    int age;

    std::default_random_engine generator;

    // todo, relationships, childhood, you know... almost everything.

    public: 
    Person();
    std::string getType();
    Coordinate getCoordinate();

    bool wantToEat();
    void feed();
    bool wantToBeEntertain();
    bool timeToDie();
    void simulateTurn();
    void generateKid();
};

#endif