#ifndef INVESTOR_H
#define INVESTOR_H

#include <string>
#include <vector>

#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>

#include "Stock.h"

class Investor {
    public:
    Investor(std::string name);
    Investor(std::string name, std::string host, std::string port);
    double getFunds();
    void alertYearEnd();

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