#ifndef PERSON_DTO_H
#define PERSON_DTO_H

#include "../Deserializable/Deserializable.h"
#include <string>
#include "CoordinateDto.h"

struct PersonDto;
void to_json(json&, const PersonDto&);
void from_json(const json&, PersonDto&);

struct PersonDto: public Deserializable {
    public:
    CoordinateDto coordinate;
    int funds;

    std::string toString() override {
        json j = *this;
        return j.dump();
    }
};


void to_json(json& j, const PersonDto& person) {
    j = json{
        {"coordinate", person.coordinate}, 
        {"funds", person.funds}
    };
}

void from_json(const json& j, PersonDto& person) {
    j.at("coordinate").get_to(person.coordinate);
    j.at("funds").get_to(person.funds);
}
#endif