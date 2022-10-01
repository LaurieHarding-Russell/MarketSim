#include "Map.h"

Map::Map(Coordinate topLeft, Coordinate bottomRight) {
    this->topLeft = topLeft;
    this->bottomRight = bottomRight;
}

std::vector<Resource> Map::getResources() {
    return resources;
}

void Map::addResource(Resource resource) {
    if (validateResourceIsInMap(resource)) {
        throw std::invalid_argument( "Resource outside of map added" );
    }
    this->resources.push_back(resource);
}

bool Map::validateResourceIsInMap(Resource resource) {
    return validateResourceIsInMap(resource.getCoordinate());
}

bool Map::validateResourceIsInMap(Coordinate resource) {
    return this->topLeft.getX() <= resource.getX() &&
            this->topLeft.getY() <= resource.getY() &&
            this->bottomRight.getX() >= resource.getX() &&
            this->bottomRight.getY() >= resource.getY();
}