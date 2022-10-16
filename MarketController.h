#ifndef MARKET_CONTROLLER_H
#define MARKET_CONTROLLER_H

#include <served/served.hpp>
#include <served/plugins.hpp>
#include <vector>
#include <string>

#include "single_include/nlohmann/json.hpp"

#include "WorldSim/World.h"

#include "Api/WorldDto.h"

#include "Transformers.h"

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
            std::cout << "Market Controller Init\n";

            mux->handle(base + "/data")
                .get([&](served::response & res, const served::request & req) {
                    WorldDto worldDto = toWorldDto(world);
                    res << worldDto.toString();
                });

            mux->handle(base + "/reset")
                .get([&](served::response & res, const served::request & req) {
                    world->reset();
                    res << "";
                });

            mux->handle(base + "/simulate-year")
                .get([&](served::response & res, const served::request & req) {
                    world->simulateYear();
                    WorldDto worldDto = toWorldDto(world);
                    res << worldDto.toString();
                });

            mux->handle(base + "/get-year")
                .get([&](served::response & res, const served::request & req) {
                    res << std::to_string(world->getYear());
                });
        }
};

#endif