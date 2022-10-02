#ifndef MAP_H
#define MAP_H

#include "Coordinate.h"
#include "Resource.h"
#include <vector>

#include <stdlib.h>
#include <time.h>
#include <stdexcept>
#include <random>

class Map {

    private:
    Coordinate topLeft;
    Coordinate bottomRight;
    std::default_random_engine generator;

    public:
    Map();
    Map(Coordinate topLeft, Coordinate bottomRight);
    bool validateResourceIsInMap(Resource resource);
    bool validateResourceIsInMap(Coordinate resource);

    Coordinate getValidCoordinate();
};

#endif