#include <iostream>
#include <gtest/gtest.h>
#include <string>
#include "InvestorController.h"
#include <served/served.hpp>
#include <served/plugins.hpp>


TEST(InvestorControllerTest, registerHappyPath) {
  served::multiplexer* mux = new served::multiplexer();
  World *world = new World();

  InvestorController* investorController = new InvestorController(mux, world);

  investorController->init();

  served::net::server server("127.0.0.1", "8080", *mux);

  server.run(10, false);  
  sleep(1);
  server.stop();

  delete world;
  delete mux;
  delete investorController;
}

TEST(InvestorControllerTest, listCompanies) {

}

TEST(InvestorControllerTest, buyStock) {

}
