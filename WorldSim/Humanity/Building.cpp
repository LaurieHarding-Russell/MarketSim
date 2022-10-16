#include "Building.h"

// FIXME
std::string Building::getType() {
    return "FarmLand";
}

Coordinate Building::getCoordinate() {
    return this->coordinate;
}

Building Building::setCoordinate(Coordinate coordinate) {
    this->coordinate = coordinate;
    return *this;
}