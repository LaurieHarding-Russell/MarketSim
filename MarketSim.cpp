#include <served/served.hpp>
#include <served/plugins.hpp>

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/uuid/uuid_generators.hpp>

#include <fstream>
#include <sstream>
#include <string>

#include "MarketController.h"
#include "InvestorController.h"

int main() {
	// fixme shared_ptr ?
    served::multiplexer* mux = new served::multiplexer();
	World *world = new World();

    MarketController* marketController = new MarketController(mux, world);
	InvestorController* investorController = new InvestorController(mux, world);

	marketController->init();
	investorController->init();

	served::net::server server("127.0.0.1", "8080", *mux);
	server.run(10);

	delete world;
	delete mux;
	delete marketController;
	delete investorController;
	return (EXIT_SUCCESS);
}  