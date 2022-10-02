#include <iostream>
#include <gtest/gtest.h>
#include <string>
#include "../WorldSim/World.h"

TEST(WorldTest, generatesAMapWithObjectsWithinBounds) {
  World world = World();

  std::string returnValue = world.getStockmarketData();
  EXPECT_GT(returnValue.length(), 0);
  json jsonValue = json::parse(returnValue);

  EXPECT_EQ(jsonValue["year"], 0);
  // EXPECT_GT(jsonValue["investor"].size(), 0);
  EXPECT_GT(jsonValue["companies"].size(), 24);

  EXPECT_GT(jsonValue["companies"][0]["funds"], -1);
  EXPECT_NE(jsonValue["companies"][0]["name"], "");

}
