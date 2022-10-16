#include "Coordinate.h"

double Coordinate::getX() {
    return x;
}

double Coordinate::getY() {
    return y;
}

Coordinate Coordinate::setX(double x) {
    this->x = x;
    return *this;
}

Coordinate Coordinate::setY(double y) {
    this->y = y;
    return *this;
}