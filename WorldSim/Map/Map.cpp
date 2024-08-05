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
    std::uniform_real_distribution<double> distributionX(topLeft.getX(), bottomRight.getX());
    std::uniform_real_distribution<double> distributionY(topLeft.getY(), bottomRight.getY());

    return Coordinate()
        .setX(distributionX(generator))
        .setY(distributionY(generator));
}

bool Map::validateTangibleIsInMap(Tangible &tangible) {
    return validateTangibleIsInMap(tangible.getCoordinate());
}

bool Map::validateTangibleIsInMap(Coordinate tangible) {
    return this->topLeft.getX() <= tangible.getX() &&
            this->topLeft.getY() <= tangible.getY() &&
            this->bottomRight.getX() >= tangible.getX() &&
            this->bottomRight.getY() >= tangible.getY();
}

Coordinate Map::getTopLeft() {
    return this->topLeft;
}

Coordinate Map::getBottomRight() {
    return this->bottomRight;
}