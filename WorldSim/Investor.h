#ifndef INVESTOR_H
#define INVESTOR_H

#include <string>
#include <vector>

#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>

#include "single_include/nlohmann/json.hpp"

#include "Stock.h"

namespace beast = boost::beast;     // from <boost/beast.hpp>
namespace http = beast::http;       // from <boost/beast/http.hpp>
namespace net = boost::asio;        // from <boost/asio.hpp>
using tcp = net::ip::tcp;           // from <boost/asio/ip/tcp.hpp>
using json = nlohmann::json;

class Investor {
    public:
    Investor(std::string name);
    Investor(std::string name, std::string host, std::string port);
    double getFunds();
    void alertYearEnd();

    friend void to_json(json& j, const Investor& investor);
    friend void from_json(const json& j, Investor& investor);

    private:
    void callBack(std::string host, std::string port, std::string url);

    std::string name;
    double funds;

    std::string host;
    std::string port;
    std::string url;

    std::vector<Stock> stock;
};

#endif