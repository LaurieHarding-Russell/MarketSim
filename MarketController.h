#ifndef MARKET_CONTROLLER_H
#define MARKET_CONTROLLER_H

#include <served/served.hpp>
#include <served/plugins.hpp>
#include <vector>

#include "single_include/nlohmann/json.hpp"

#include "WorldSim/World.h"
#include "MarketController.h"

using json = nlohmann::json;

class MarketController {

    private:
        World *world;
        served::multiplexer *mux;

        
    public:
        MarketController(served::multiplexer *mux, World *world) {
            this->mux = mux;
            this->world = world;
        }

        void init() {
            mux->handle("/data")
                .get([&](served::response & res, const served::request & req) {
                    res << world->getStockmarketData();
                });

            mux->handle("/start")
                .get([&](served::response & res, const served::request & req) {
                    res << world->reset();
                });

            mux->handle("/simulate-year")
                .get([&](served::response & res, const served::request & req) {
                    res << world->simulateYear();
                });

            mux->handle("/get-year")
                .get([&](served::response & res, const served::request & req) {
                    res << std::to_string(world->getYear());
                });

            mux->handle("/register")
                .post([&](served::response & res, const served::request & req) {

                    json body = json::parse(req.body()); 
                    std::string name = body["name"];
                    std::string host = body["host"];
                    std::string port = body["port"];
                    
                    if (host != "" && port != "") {
                        res << world->registerTradingBot(name, host, port);
                    } else {
                        res << world->registerTradingBot(name);
                    }
                });
        }
};

#endif