#include <iostream>
#include <gtest/gtest.h>
#include <string>
#include "../WorldSim/World.h"

// FIXME
TEST(WorldTest, generateAWorldOnCreate) {
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

// TEST(WorldTest, worldSimulateAYear) {
//   World world = World();

//   std::string returnValue = world.simulateYear();
//   EXPECT_GT(returnValue.length(), 0);
//   json jsonValue = json::parse(returnValue);

//   EXPECT_EQ(jsonValue["year"], 1);
// }

// TEST(WorldTest, worldTestReset) {
//   World world = World();

//   std::string returnValue = world.simulateYear();
//   EXPECT_GT(returnValue.length(), 0);
//   json jsonValue = json::parse(returnValue);

//   EXPECT_EQ(jsonValue["year"], 1);

//   returnValue = world.reset();
//   jsonValue = json::parse(returnValue);
//   EXPECT_EQ(jsonValue["year"], 0);
// }
