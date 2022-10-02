#include <iostream>
#include <gtest/gtest.h>
#include <string>
#include "../WorldSim/World.h"

TEST(WorldTest, generatesAMapWithObjectsWithinBounds) {
  World world = World();

  std::string returnValue = world.getStockmarketData();
  EXPECT_GT(returnValue.length(), 0);
  // EXPECT_EQ(7 * 6, 42);
}
