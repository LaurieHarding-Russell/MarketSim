#ifndef STOCK_H
#define STOCK_H

#include "Company.h"
#include "../Deserializable/Deserializable.h"

class Stock: public Deserializable {
    public:

    friend void to_json(json& j, const Stock& investor);
    friend void from_json(const json& j, Stock& investor);

    private:
    Company* company;
    double Shares;
};

#endif