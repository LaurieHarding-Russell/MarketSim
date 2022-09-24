#ifndef RESOURCE_H
#define RESOURCE_H

#include "Coordinate.h"

enum ResouceType {
    FARMABLE_LAND,
    WATER,
    METAL,
    
};

class Resource {
    private:
    ResouceType type;
    Coordinate coordinate;
    
    public:
    ResouceType getType();

    Coordinate getCoordinate();

};
#endif