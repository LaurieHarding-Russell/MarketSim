#ifndef COMPANY_DTO_H
#define COMPANY_DTO_H

#include "../Deserializable/Deserializable.h"
#include <string>

struct CompanyDto;
void to_json(json&, const CompanyDto&);
void from_json(const json&, CompanyDto&);

struct CompanyDto: public Deserializable {
    public:
    std::string name;
    int funds;

    std::string toString() override {
        json j = *this;
        return j.dump();
    }
};


void to_json(json& j, const CompanyDto& company) {
    j = json{
        {"name", company.name}, 
        {"funds", company.funds}
    };
}

void from_json(const json& j, CompanyDto& company) {
    j.at("name").get_to(company.name);
    j.at("funds").get_to(company.funds);
}
#endif