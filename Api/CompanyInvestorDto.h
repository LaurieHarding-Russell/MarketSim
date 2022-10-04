#ifndef COMPANY_INVESTOR_DTO_H
#define COMPANY_INVESTOR_DTO_H

#include "../Deserializable/Deserializable.h"
#include <string>

struct CompanyInvestorDto;
void to_json(json&, const CompanyInvestorDto&);
void from_json(const json&, CompanyInvestorDto&);

struct CompanyInvestorDto: public Deserializable {
    public:
    std::string name;
    int funds;
    int sketchiness;

    std::string toString() {
        json j = *this;
        return j.dump();
    }
};

void to_json(json& j, const CompanyInvestorDto& registerInvestor) {
    j = json{
        {"name", registerInvestor.name},
        {"funds", registerInvestor.funds},
        {"sketchiness", registerInvestor.sketchiness}
    };
}

void from_json(const json& j, CompanyInvestorDto& registerInvestor) {
    j.at("name").get_to(registerInvestor.name);
    j.at("funds").get_to(registerInvestor.funds);
    j.at("sketchiness").get_to(registerInvestor.sketchiness);
}

#endif