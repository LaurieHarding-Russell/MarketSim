#ifndef DESERIALIZABLE_H
#define DESERIALIZABLE_H

#include <stdexcept>
#include <string>
#include "single_include/nlohmann/json.hpp"

using json = nlohmann::json;

class Deserializable;
void to_json(json&, const Deserializable&); 
void from_json(const json&, Deserializable&);

// FIXME, think about this.
class Deserializable {
    public:
    virtual std::string toString() {
        json j = *this;
        return j.dump();
    }
};
    
void to_json(json& j, const Deserializable& registerInvestor) {
    j = json{};
}

void from_json(const json& j, Deserializable& registerInvestor) {

}
#endif