#pragma once

#include <served/served.hpp>
#include <served/plugins.hpp>
#include <vector>

#include "World.h"

static class MarketController {

    private:
        World *world;
        served::multiplexer *mux;

        
    public:
        MarketController(served::multiplexer *mux, World *world) {
            this->mux = mux;
            this->world = world;
        }

        void marketController(served::multiplexer &mux) {
            mux.handle("/data")
                .get([](served::response & res, const served::request & req) {
                    res << "Hello world!";
                });

            mux.handle("/start")
                .get([](served::response & res, const served::request & req) {
                    res << "Starting!";
                });

            mux.handle("/simulate-year")
                .get([](served::response & res, const served::request & req) {
                    res << "simulate-year!";
                });
        }

}