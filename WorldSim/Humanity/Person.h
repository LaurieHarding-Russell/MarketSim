#ifndef PERSON_H
#define PERSON_H

#include "../Map/Resource.h"
#include "../Map/MapUtil.h"
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
    int coruption;
    int age;
    double travelAbility;

    std::default_random_engine generator;

    // todo, relationships, childhood, you know... almost everything.

    public: 
    Person();
    std::string getType();
    Coordinate getCoordinate();

    bool wantToEat();
    void feed();
    bool isFed();
    bool canProduceKid();
    bool wantToBeEntertain();
    bool timeToDie();
    void simulateTurn();
    Person generateKid();
    int getIntelligence();
    int getCoruption();
    double getProductivityScore();
    double getPercievedProductivityScore(int viewersIntelligence);
    bool isAlive();
    bool canTravelTo(Coordinate);

    bool shouldDie();
};

#endif