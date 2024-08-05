#include <iostream>
#include <gtest/gtest.h>
#include <string>
#include "./Person.h"

TEST(PersonTest, personShouldMoveTowardsGoal) {
    Person person = Person();

    ASSERT_EQ(map.validateTangibleIsInMap(outsideObject), false);
}

TEST(MapUtil, correctDistanceBetweenCoordinates) {
    ASSERT_EQ(
        distance(
            Coordinate().setX(1.0).setY(1.0),
            Coordinate().setX(1.0).setY(3.0)
        ),
        2
    );
}