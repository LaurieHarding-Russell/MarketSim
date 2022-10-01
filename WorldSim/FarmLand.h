#ifndef FARM_LAND_H
#define FARM_LAND_H

#include "Map/Resource.h"

class FarmLand: public Resource {
    private:
    Coordinate coordinate;

    public: 

    std::string getType();
    Coordinate getCoordinate();
};

#endif