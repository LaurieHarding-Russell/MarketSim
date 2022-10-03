
#include "boost/asio.hpp"
#include "boost/beast.hpp"

#include <cstdlib>
#include <functional>
#include <iostream>
#include <memory>
#include <string>
#include "../Api/RegisterInvestorDto.h"
#include "../Api/InvestorDto.h"

namespace beast = boost::beast;
namespace http = beast::http;
namespace asio = boost::asio;
using tcp = asio::ip::tcp;

// FIXME, need make these insertable.
std::string HOST = "127.0.0.1:8080";
std::string INVESTOR_ENDPOINT = "/investor";


http::request<http::string_body> setupRequest(beast::tcp_stream stream) {
    http::request<http::string_body> request;
    request.version(11);
    request.set(http::field::host, HOST);
    request.set(http::field::content_type, "application/json");
}

std::string getResponse(beast::tcp_stream stream, http::request<http::string_body> request) {
    boost::beast::http::write(stream, request);
    boost::beast::flat_buffer buffer;
    boost::beast::http::response<boost::beast::http::dynamic_body> response;
    boost::beast::http::read(stream, buffer, response);

    std::string responseString = boost::asio::buffer_cast<const char*>(response.body.data());
}

InvestorDto RegisterData(RegisterInvestorDto registerInvestorDto) {
    asio::io_context context;
    beast::tcp_stream stream(context);
    stream.connect(tcp::resolver(context).resolve(HOST, "http"));

    http::request<http::string_body> request = setupRequest(stream);

    request.method(http::verb::post);
    request.target(INVESTOR_ENDPOINT + "/register");
    request.body() = registerInvestorDto.toString();
    request.prepare_payload();

    return json::parse(getResponse(stream, request));
}