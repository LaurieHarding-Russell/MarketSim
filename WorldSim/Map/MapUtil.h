#ifndef MapUtil_H
#define MapUtil_H

#include "Coordinate.h"
#include <cmath>

static double distance(Coordinate a, Coordinate b) {
    return sqrt(
        pow(a.getX() - b.getX(), 2) +
        pow(a.getY() - b.getY(), 2)
    );
}

#endif