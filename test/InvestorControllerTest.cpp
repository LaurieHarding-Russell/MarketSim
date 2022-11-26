#include <iostream>
#include <gtest/gtest.h>
#include <string>
#include "InvestorController.h"
#include <served/served.hpp>
#include <served/plugins.hpp>
#include "CppClient.h"


TEST(InvestorControllerTest, registerHappyPath) {
  served::multiplexer* mux = new served::multiplexer();
  World *world = new World();

  InvestorController* investorController = new InvestorController(mux, world);

  investorController->init();

  served::net::server server("127.0.0.1", "8080", *mux);

  server.run(10, false);  
  sleep(1); // Don't know if I even need this.
  RegisterInvestorDto registerInvestorDto;
  registerInvestorDto.name = "ME";
  InvestorDto investorDto = CppClient::registerBot(registerInvestorDto);

  EXPECT_EQ(investorDto.name, registerInvestorDto.name);
  EXPECT_EQ(investorDto.funds, 1000);

  server.stop();

  delete world;
  delete mux;
  delete investorController;
}

TEST(InvestorControllerTest, listCompanies) {

}

TEST(InvestorControllerTest, buyStock) {

}
