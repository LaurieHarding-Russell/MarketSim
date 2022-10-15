#ifndef COORDINATE_DTO_H
#define COORDINATE_DTO_H

#include "../Deserializable/Deserializable.h"
#include <string>

struct CoordinateDto;
void to_json(json&, const CoordinateDto&);
void from_json(const json&, CoordinateDto&);

struct CoordinateDto: public Deserializable {
    public:
    double x;
    double y;

    std::string toString() override {
        json j = *this;
        return j.dump();
    }
};


void to_json(json& j, const CoordinateDto& coordinate) {
    j = json{
        {"x", coordinate.x}, 
        {"y", coordinate.y}
    };
}

void from_json(const json& j, CoordinateDto& coordinate) {
    j.at("x").get_to(coordinate.x);
    j.at("y").get_to(coordinate.y);
}
#endif