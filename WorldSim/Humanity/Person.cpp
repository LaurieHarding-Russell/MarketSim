#include "Person.h"

Person::Person() {
    generator = std::default_random_engine(std::random_device{}());
    speed = 10;
}

std::string Person::getType() {
    return "Person";
}

Coordinate Person::getCoordinate() {
    return coordinate;
}

bool Person::wantToEat() {
    return hunger < 4;
}

void Person::feed() {
    hunger = hunger + 1;
}

bool Person::isBored() {
    return happy < 3;
}


bool Person::timeToDie(double currentTime) {
    return health < 0 || hunger == 0 || currentTime - birthday > 1000;
}

void Person::moveUpdate() {
    if(distance(moveGoal, coordinate) < speed) {
        coordinate = moveGoal
    }
    moveGoal
}

void Person::setMoveGoal(Coordinate goalLocation) {

}

void Person::healthUpdate() {
    if (happy < 3 || hunger < 3) {
        health = health - 1;
    }
}

int Person::getIntelligence() {
    return intelligence;
}

int Person::getEducation() {
    return education;
}

int Person::getCoruption() {
    return coruption;
}

double Person::getProductivityScore() {
    double happyModifier = (happy + health) / 200;
    double capabilityModifier = (education/100.0) * (intelligence/100);

    return (happyModifier * capabilityModifier);
}

double Person::getPercievedProductivityScore(int viewersIntelligence) {
    if (intelligence > viewersIntelligence) {
        return getProductivityScore();
    }
    return (getProductivityScore() * coruption/100);
}

bool Person::canProduceKid() {
    return false; // FIXME, figure out age later
}