#ifndef INVESTOR_CONTROLLER_H
#define INVESTOR_CONTROLLER_H

#include <served/served.hpp>
#include <served/plugins.hpp>
#include <vector>
#include <string>

#include "single_include/nlohmann/json.hpp"

#include "WorldSim/World.h"
#include "Api/CompanyInvestorDto.h"
#include "Api/RegisterInvestorDto.h"
#include "Api/InvestorDto.h"
#include "Api/BuyDto.h"

using json = nlohmann::json;

class InvestorController {

    private:
        World *world;
        served::multiplexer *mux;
        const std::string base = "/investor";

        
    public:
        InvestorController(served::multiplexer *mux, World *world) {
            this->mux = mux;
            this->world = world;
        }

        void init() {
            mux->handle(base + "/register")
                .post([&](served::response & res, const served::request & req) {

                    RegisterInvestorDto registerInvestorDto = json::parse(req.body()); 
                    std::string name = registerInvestorDto.name;
                    
                    Investor investor = world->registerTradingBot(name);
                    InvestorDto investorDto;
                    investorDto.funds = investor.getFunds();
                    investorDto.name = investor.getName();
                    res << investorDto.toString();
                });

            mux->handle(base + "/get-year")
                .get([&](served::response & res, const served::request & req) {
                    res << std::to_string(world->getYear());
                });

            mux->handle(base + "/get-list-of-companies")
                .get([&](served::response & res, const served::request & req) {
                    res << "TODO";
                });

            // TODO: Note corrupt companies may "hide" bad financials.
            mux->handle(base + "/get-company-financials")
                .get([&](served::response & res, const served::request & req) {
                    res << "TODO";
                });

            mux->handle(base + "/buy")
                .post([&](served::response & res, const served::request & req) {
                    BuyDto buyDto = json::parse(req.body()); 
                    res << "TODO";
                });
        }
};

#endif