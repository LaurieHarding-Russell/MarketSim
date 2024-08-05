#ifndef MAP_H
#define MAP_H

#include "Coordinate.h"
#include "Tangible.h"
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
    bool validateTangibleIsInMap(Tangible& tangible);
    bool validateTangibleIsInMap(Coordinate tangibleCoordinate);

    Coordinate getTopLeft();
    Coordinate getBottomRight();

    Coordinate getValidCoordinate();
};

#endif