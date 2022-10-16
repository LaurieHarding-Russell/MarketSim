#ifndef WORLD_DTO_H
#define WORLD_DTO_H

#include "../Deserializable/Deserializable.h"
#include <string>
#include "CompanyDto.h"
#include "PersonDto.h"
#include "InvestorDto.h"

struct WorldDto;
void to_json(json&, const WorldDto&);
void from_json(const json&, WorldDto&);


struct WorldDto: public Deserializable {
    public:
    int year;
    std::vector<CompanyDto> companies;
    std::vector<PersonDto> people;
    std::vector<InvestorDto> investors;

    std::string toString() override {
        json j = *this;
        return j.dump();
    }
};


void to_json(json& j, const WorldDto& worldDto) {
    j = json{
        {"year", worldDto.year},
        {"companies", worldDto.companies},
        {"people", worldDto.people},
        {"investors", worldDto.investors}
    };
}

void from_json(const json& j, WorldDto& worldDto) {
    j.at("year").get_to(worldDto.year);
    j.at("companies").get_to(worldDto.companies);
    j.at("people").get_to(worldDto.people);
    j.at("investors").get_to(worldDto.investors);
}

#endif