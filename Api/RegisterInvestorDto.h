#ifndef REGISTER_INVESTOR_DTO_H
#define REGISTER_INVESTOR_DTO_H

#include "../Deserializable/Deserializable.h"
#include <string>

struct RegisterInvestorDto;
void to_json(json&, const RegisterInvestorDto&);
void from_json(const json&, RegisterInvestorDto&);


struct RegisterInvestorDto: public Deserializable {
    public:
    std::string name;

    std::string toString() {
        json j = *this;
        return j.dump();
    }
};


void to_json(json& j, const RegisterInvestorDto& registerInvestor) {
    j = json{{"name", registerInvestor.name}};
}

void from_json(const json& j, RegisterInvestorDto& registerInvestor) {
    j.at("name").get_to(registerInvestor.name);
}

#endif