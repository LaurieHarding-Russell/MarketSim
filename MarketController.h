#ifndef MARKET_CONTROLLER_H
#define MARKET_CONTROLLER_H

#include <served/served.hpp>
#include <served/plugins.hpp>
#include <vector>
#include <string>

#include "single_include/nlohmann/json.hpp"

#include "WorldSim/World.h"

using json = nlohmann::json;

class MarketController {

    private:
        World *world;
        served::multiplexer *mux;
        const std::string base = "/market";

        
    public:
        MarketController(served::multiplexer *mux, World *world) {
            this->mux = mux;
            this->world = world;
        }

        void init() {
            // mux->handle(base + "/data")
            //     .get([&](served::response & res, const served::request & req) {
            //         res << world->getStockmarketData();
            //     });

            mux->handle(base + "/start")
                .get([&](served::response & res, const served::request & req) {
                    world->reset();
                    res << "";
                });

            mux->handle(base + "/simulate-year")
                .get([&](served::response & res, const served::request & req) {
                    world->simulateYear();
                    res << "";
                });

            mux->handle(base + "/get-year")
                .get([&](served::response & res, const served::request & req) {
                    res << std::to_string(world->getYear());
                });
        }
};

#endif