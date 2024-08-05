#ifndef BUILDING_H
#define BUILDING_H

#include "../Map/Tangible.h"

class Building: public Tangible {
    private:
    Coordinate coordinate;

    public: 

    std::string getType();
    Coordinate getCoordinate();

    Building setCoordinate(Coordinate coordinate);
};

#endif