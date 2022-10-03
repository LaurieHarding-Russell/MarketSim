#ifndef BUY_DTO_H
#define BUY_DTO_H

#include "../Deserializable/Deserializable.h"
#include <string>

struct BuyDto;
void to_json(json&, const BuyDto&);
void from_json(const json&, BuyDto&);

struct BuyDto: public Deserializable {
    public:
    std::string name;
    int maxPrice;
    int maxShares;
    int maxFunds;
};


void to_json(json& j, const BuyDto& buyDto) {
    j = json{
        {"name", buyDto.name},
        {"maxPrice", buyDto.maxPrice},
        {"maxShares", buyDto.maxShares},
        {"maxFunds", buyDto.maxFunds}
    };
}

void from_json(const json& j, BuyDto& buyDto) {
    j.at("name").get_to(buyDto.name);
    j.at("maxPrice").get_to(buyDto.maxPrice);
    j.at("maxShares").get_to(buyDto.maxShares);
    j.at("maxFunds").get_to(buyDto.maxFunds);
}


#endif