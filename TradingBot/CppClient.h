
#include "boost/asio.hpp"
#include "boost/beast.hpp"

#include <cstdlib>
#include <iostream>
#include <string>
#include "../Api/RegisterInvestorDto.h"
#include "../Api/InvestorDto.h"

namespace beast = boost::beast;
namespace http = beast::http;
namespace asio = boost::asio;
using tcp = asio::ip::tcp;

namespace CppClient {

    // FIXME, need make these insertable.
    std::string HOST = "localhost";
    std::string INVESTOR_ENDPOINT = "/investor";


    http::request<http::string_body> setupRequest() {
        http::request<http::string_body> request;
        request.version(11);
        request.set(http::field::host, HOST);
        request.set(http::field::content_type, "application/json");
        return request;
    }

    std::string getResponse(http::request<http::string_body> request) {
        asio::io_service io_service;
        tcp::resolver resolver(io_service);
        tcp::resolver::query query(HOST,"8080",tcp::resolver::query::canonical_name);
        tcp::resolver::iterator endpoint_iterator = resolver.resolve(query);
        tcp::socket socket(io_service);
        asio::connect(socket, endpoint_iterator);

        // socket.connect(io_service);
        http::write(socket, request);
        beast::flat_buffer buffer;
        http::response<http::dynamic_body> response;
        http::read(socket, buffer, response);
        
        std::string s = beast::buffers_to_string(response.body().data());
        return s;
    }

    InvestorDto registerBot(RegisterInvestorDto registerInvestorDto) {
        http::request<http::string_body> request = setupRequest();
        request.method(http::verb::post);
        request.target(INVESTOR_ENDPOINT + "/register");
        request.body() = registerInvestorDto.toString();
        request.prepare_payload();

        return json::parse(getResponse(request));
    }
}