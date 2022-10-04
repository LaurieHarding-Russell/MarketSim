#ifndef INVESTOR_DTO_H
#define INVESTOR_DTO_H

#include "../Deserializable/Deserializable.h"
#include <string>

struct InvestorDto;
void to_json(json&, const InvestorDto&);
void from_json(const json&, InvestorDto&);

struct InvestorDto: public Deserializable {
    public:
    std::string name;
    int funds;

    std::string toString() {
        json j = *this;
        return j.dump();
    }
};


void to_json(json& j, const InvestorDto& investorDto) {
    j = json{
        {"name", investorDto.name},
        {"funds", investorDto.funds}
    };
}

void from_json(const json& j, InvestorDto& investorDto) {
    j.at("name").get_to(investorDto.name);
    j.at("funds").get_to(investorDto.funds);
}

#endif