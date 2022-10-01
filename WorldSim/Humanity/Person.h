#ifndef PERSON_H
#define PERSON_H

#include "../Map/Resource.h"

class Person: public Resource {
    private:
    Coordinate coordinate;

    public: 
    std::string getType();
    Coordinate getCoordinate();
};

#endif