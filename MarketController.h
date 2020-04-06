
#include <served/served.hpp>
#include <served/plugins.hpp>

namespace MarketController {

    void marketController(served::multiplexer &mux) {
        mux.handle("/data")
            .get([](served::response & res, const served::request & req) {
                res << "Hello world!";
            });

        mux.handle("/start")
            .get([](served::response & res, const served::request & req) {
                res << "Hello world!";
            });

        mux.handle("/simulate-year")
            .get([](served::response & res, const served::request & req) {
                res << "Hello world!";
            });
    }

}