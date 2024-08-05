#ifndef PERSON_H
#define PERSON_H

#include "../Map/Tangible.h"
#include "../Map/MapUtil.h"
#include <random>

class Person: public Tangible {
    protected:
    Coordinate coordinate;
    int hunger; // 0 - 5; 0 == starving, 1-2 unhealthy lack of food, 3-5 has enough food. 
    bool sex;
    int happy; // 0 = I don't see the point of living, 1 = depressed, 2 I need to do something, 3-4 = ok, 5 = pure bliss
    int health;
    int education;
    int intelligence;
    int coruption;
    double birthday;
    double speed;
    Coordinate moveGoal;

    std::default_random_engine generator;

    // todo, relationships, childhood, you know... almost everything.

    public: 
    Person();
    std::string getType() override;
    Coordinate getCoordinate() override;

    int getEducation();
    bool wantToEat();
    void feed();

    bool canProduceKid();
    bool isBored();

    bool timeToDie(double currentTime);
    
    void healthUpdate();
    void moveUpdate();
    void setMoveGoal(Coordinate goalLocation);

    int getIntelligence();
    int getCoruption();
    double getProductivityScore();
    double getPercievedProductivityScore(int viewersIntelligence);
};

#endif