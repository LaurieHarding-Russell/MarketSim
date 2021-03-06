#ifndef INVESTOR_CONTROLLER_H
#define INVESTOR_CONTROLLER_H

#include <served/served.hpp>
#include <served/plugins.hpp>
#include <vector>
#include <string>

#include "single_include/nlohmann/json.hpp"

#include "WorldSim/World.h"

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