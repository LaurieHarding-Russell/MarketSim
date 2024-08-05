#ifndef MapUtil_H
#define MapUtil_H

#include "Coordinate.h"
#include <cmath>
#include <iostream>

static double distance(Coordinate a, Coordinate b);
static Coordinate vectorOfCoordinates(Coordinate a, Coordinate b);
static Coordinate move(Coordinate location, Coordinate destination, double length);

static double distance(Coordinate a, Coordinate b) {
    return sqrt(
        pow(a.getX() - b.getX(), 2) +
        pow(a.getY() - b.getY(), 2)
    );
}

static Coordinate vectorOfCoordinates(Coordinate start, Coordinate end) {
    return Coordinate()
                .setX(end.getX() - start.getX())
                .setY(end.getY() - start.getY());
}

static Coordinate move(Coordinate start, Coordinate end, double velocity) {
    double magnitude =  distance(start, end);
    if (magnitude <= velocity) {
        return end;
    }

    Coordinate vector = vectorOfCoordinates(start, end);

    Coordinate normalizedVector = Coordinate()
                    .setX(vector.getX() / magnitude)
                    .setY(vector.getY() / magnitude);

    std::cout << "vector.getY():: " << vector.getY() << '\n';

    return Coordinate()
                    .setX(start.getX() + (normalizedVector.getX() * velocity))
                    .setY(start.getY() + (normalizedVector.getY() * velocity));
}

#endif