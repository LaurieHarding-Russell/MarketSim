#include "Person.h"

std::string Person::getType() {
    return "FarmLand";
}

Coordinate Person::getCoordinate() {
    return this->coordinate;
}

bool Person::wantToEat() {
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

void Person::simulateTurn(){
    health = health - 1;
}