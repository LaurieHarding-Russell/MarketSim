#include <served/served.hpp>
#include <served/plugins.hpp>

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/uuid/uuid_generators.hpp>

#include <fstream>
#include <sstream>
#include <string>

#include "MarketController.h"

int main() {
    served::multiplexer mux;

	// GET /hello
    MarketController::marketController(mux);

	// Create the server and run with 10 handler threads.
	served::net::server server("127.0.0.1", "8080", mux);
	server.run(10);
	return (EXIT_SUCCESS);
}  