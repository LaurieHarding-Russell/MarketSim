#include "Map.h"

Map::Map() {
    Map(
        Coordinate()
            .setX(0.0)
            .setY(0.0),
        Coordinate()
            .setX(0.0)
            .setY(0.0)
    );
}

Map::Map(Coordinate topLeft, Coordinate bottomRight) {
    std::random_device rd;
    generator = std::default_random_engine(rd());

    this->topLeft = topLeft;
    this->bottomRight = bottomRight;
}

Coordinate Map::getValidCoordinate() {
    std::uniform_real_distribution<double> distributionX(topLeft.getX(), bottomRight.getX() - topLeft.getX());
    std::uniform_real_distribution<double> distributionY(topLeft.getY(), bottomRight.getY() - topLeft.getY());

    return Coordinate()
        .setX(distributionX(generator))
        .setY(distributionY(generator));
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