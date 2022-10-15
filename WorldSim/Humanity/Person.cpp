#include "Person.h"

Person::Person() {
    generator = std::default_random_engine(std::random_device{}());
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
    age = age + 1;
}

void Person::generateKid() {
    std::uniform_int_distribution<int> sexDistribution(0, 1);
    std::uniform_int_distribution<int> educationDistribution(0, education);
    std::uniform_int_distribution<int> intelligenceDistribution(0, 100);

    Person person = Person();
    person.education = educationDistribution(generator);
    person.sex = sexDistribution(generator);
    person.fed = true;
    person.happy = 100;
    person.health = 100;
    person.age = 0;
    person.intelligence = intelligenceDistribution(generator);
    person.coordinate = Coordinate();
    person.coordinate.setX(coordinate.getX());
    person.coordinate.setY(coordinate.getY());
}