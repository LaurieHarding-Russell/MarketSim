#include "Coordinate.h"

double Coordinate::getX() {
    return x;
}

double Coordinate::getY() {
    return x;
}

Coordinate Coordinate::setX(double x) {
    this->x = x;
    return *this;
}

Coordinate Coordinate::setY(double y) {
    this->y = y;
    return *this;
}