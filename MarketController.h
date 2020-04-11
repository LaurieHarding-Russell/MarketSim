#ifndef MARKET_CONTROLLER_H
#define MARKET_CONTROLLER_H

#include <served/served.hpp>
#include <served/plugins.hpp>
#include <vector>

#include "World.h"
#include "MarketController.h"

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
                    res << "simulate-year!";
                });
        }

};

#endif