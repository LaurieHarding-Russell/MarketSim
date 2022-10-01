#ifndef BUILDING_H
#define BUILDING_H

#include "../Map/Resource.h"

class Building: public Resource {
    private:
    Coordinate coordinate;

    public: 

    std::string getType();
    Coordinate getCoordinate();
};

#endif