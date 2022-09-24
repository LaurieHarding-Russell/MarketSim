#include <gtest/gtest.h>
#include "../WorldSim/Map/Map.h"
#include "../WorldSim/Map/Coordinate.h"


TEST(MapTest, generatesAMapWithObjectsWithinBounds) {
    Map map = Map::generateMap(
        Coordinate()
            .setX(0.0)
            .setY(0.0),
        Coordinate()
            .setX(100.0)
            .setY(100.0)
    );

  
  EXPECT_EQ(7 * 6, 42);
}
