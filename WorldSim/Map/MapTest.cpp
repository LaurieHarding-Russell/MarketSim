#include <iostream>
#include <gtest/gtest.h>
#include <string>
#include "./Map.h"
#include "./MapUtil.h"

class TestTangible: public Tangible {
    private: 
    Coordinate coordinate;

    public:
    std::string getType() override { 
        throw std::invalid_argument( "Unimplemented getType" );
    }

    void setCoordinate(Coordinate coordinate) {
        this->coordinate = coordinate;
    }

    Coordinate getCoordinate() override {
        return this->coordinate;
    }
};

TEST(MapTest, validateTangibleIsInMapCorrectly) {
    Map map = Map(
        Coordinate().setX(0.0).setY(0.0),
        Coordinate().setX(100.0).setY(100.0)
    );
    TestTangible outsideObject = TestTangible();
    outsideObject.setCoordinate(Coordinate().setX(-1.0).setY(50.0));

    TestTangible insideObject = TestTangible();
    insideObject.setCoordinate(Coordinate().setX(50.0).setY(50.0));

    ASSERT_EQ(map.validateTangibleIsInMap(outsideObject), false);
    ASSERT_EQ(map.validateTangibleIsInMap(Coordinate().setX(-1.0).setY(50.0)), false);

    ASSERT_EQ(map.validateTangibleIsInMap(insideObject), true);
    ASSERT_EQ(map.validateTangibleIsInMap(Coordinate().setX(50.0).setY(50.0)), true);
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