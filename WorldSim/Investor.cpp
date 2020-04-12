
#include "Investor.h"

namespace beast = boost::beast;     // from <boost/beast.hpp>
namespace http = beast::http;       // from <boost/beast/http.hpp>
namespace net = boost::asio;        // from <boost/asio.hpp>
using tcp = net::ip::tcp;           // from <boost/asio/ip/tcp.hpp>

Investor::Investor(std::string name) {
    // FIXME, think about this
    Investor(name, "", "");
}

Investor::Investor(std::string name, std::string host, std::string port) {
    this->name = name;
    this->host = host;
    this->port = port;
}

double Investor::getFunds() {
    return funds;
}

void Investor::alertYearEnd() {
    if (host != "") {
        callBack(host, port, "/callback");
    }
}


//Private

// I should probably find a better library for this. This is too low level... I miss jersey.
void Investor::callBack(std::string host, std::string port, std::string url) {
    net::io_context ioContext;
    tcp::resolver resolver(ioContext);
    beast::tcp_stream stream(ioContext);
    auto const results = resolver.resolve(host, port);

    stream.connect(results);
    http::request<http::string_body> request{http::verb::get, url, 11};
    request.set(http::field::host, host);
    request.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);

    http::write(stream, request);
    beast::flat_buffer buffer;
    http::response<http::dynamic_body> result;

    http::read(stream, buffer, result);

    // FIXME, what should be in the result? What should we do with it?

    beast::error_code errorCode;
    stream.socket().shutdown(tcp::socket::shutdown_both, errorCode);
}