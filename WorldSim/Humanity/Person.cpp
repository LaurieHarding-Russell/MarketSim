#include "Person.h"

Person::Person() {
    generator = std::default_random_engine(std::random_device{}());
    travelAbility = 10;
}

std::string Person::getType() {
    return "FarmLand";
}

Coordinate Person::getCoordinate() {
    return coordinate;
}

bool Person::wantToEat() {
    return fed;
}

bool Person::isFed() {
    return fed;
}

void Person::feed() {
    fed = true;
}

bool Person::wantToBeEntertain(){
    return happy < 10;
}

bool Person::timeToDie(){
    return health < 0 || fed == false;
}

void Person::simulateTurn() {
    health = health - 1;
    age = age + 1;
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

bool Person::isAlive() {
    return !fed || health == 0 || age > 200;
}

bool Person::canProduceKid() {
    return age > 18 && age < 50;
}

bool Person::canTravelTo(Coordinate location) {
    return travelAbility > distance(coordinate, location);
}