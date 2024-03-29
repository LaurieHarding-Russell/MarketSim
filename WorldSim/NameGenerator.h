#ifndef NAME_GENERATOR_H
#define NAME_GENERATOR_H

#include <string>
#include <vector>
#include <random>

namespace nameGenerator {
    const std::vector<std::string> names = {
        "Emma",
        "Olivia",
        "Ava",
        "Isabella",
        "Sophia",
        "Charlotte",
        "Mia",
        "Amelia",
        "Harper",
        "Evelyn",
        "Abigail",
        "Emily",
        "Elizabeth",
        "Mila",
        "Ella",
        "Avery",
        "Sofia",
        "Camila",
        "Aria",
        "Scarlett",
        "Victoria",
        "Madison",
        "Luna",
        "Grace",
        "Chloe",
        "Liam",
        "Noah",
        "William",
        "James",
        "Oliver",
        "Benjamin",
        "Elijah",
        "Lucas",
        "Mason",
        "Logan",
        "Alexander",
        "Ethan",
        "Jacob",
        "Michael",
        "Daniel",
        "Henry",
        "Jackson",
        "Sebastian",
        "Aiden",
        "Matthew",
        "Samuel",
        "David",
        "Joseph",
        "Carter",
        "Owen"
    };

    const std::vector<std::string> animals = {
        "Aardvark",
        "Ape",
        "Ant",
        "Baboon",
        "Bear",
        "Bird",
        "Bison"
        "Butterfly",
        "Cat",
        "Chameleon",
        "Chicken"
        "Cougar",
        "Cow",
        "Deer",
        "Dog",
        "Dolphin",
        "Duck",
        "Eagle",
        "Elk",
        "Falcon",
        "Fish",
        "Fox",
        "Hare",
        "Horse",
        "Human",
        "Hyena",
        "Lion",
        "Lobster",
        "Monkey",
        "Moose",
        "Owl",
        "Pig",
        "Pony",
        "Rabbit",
        "Shark",
        "Snake",
        "Spider",
        "Turkey",
        "Wolf"
    };

    const std::vector<std::string> things = {
        "Arrow",
        "Art",
        "Book",
        "Computer",
        "Disk",
        "Duo",
        "Energy",
        "Farm",
        "Science",
        "Shield",
        "Snowflake",
        "Sword",
        "Magic",
        "Math",
        "Music",
        "Paper",
        "Robot",
        "Rock",
        "Zombie"
    };

    const std::vector<std::string> adjuctives = {
        "Broken",
        "Bulky"
        "Cowardly"
        "Computing",
        "Calculating",
        "Cold",
        "Dangerous",
        "Daring",
        "Devious"
        "Despicable",
        "Flaming",
        "Giant",
        "Grave",
        "Gross",
        "Honorable",
        "Hot",
        "Imperial",
        "Infinity",
        "Large",
        "Limited",
        "Loud",
        "Lucky",
        "Muddy",
        "Macro",
        "Micro",
        "Sharp",
        "Small",
        "Stony",
        "Unlimited"
    };

    const int MAX_ADJUCTIVES = 2;
    const int MAX_NAMES = 2;

    const int NAME_CASE = 0;
    const int ANIMAL_CASE = 1;
    const int OBJECT_CASE = 2;

    static std::uniform_int_distribution<int> oneInThree(0, 3);        
    static std::uniform_int_distribution<int> adjustivesToUseDistribtions(0, MAX_ADJUCTIVES);
    static std::uniform_int_distribution<int> nameDistribtions(0, names.size() - 1);
    static std::uniform_int_distribution<int> animalDistribtions(0, animals.size() - 1);
    static std::uniform_int_distribution<int> thingDistribtions(0, things.size() - 1);
    static std::uniform_int_distribution<int> adjuctivesDistribtions(0, adjuctives.size() - 1);

    //FIXME, I really hope none of these combos are that terrible...
    // FIXME, probably should make it related to industry etc.
    static std::string corporateNameGenerator() {
        std::random_device rd;
        std::default_random_engine generator = std::default_random_engine(rd());

        std::string name = "";
        for (int i =0; i < adjustivesToUseDistribtions(generator); i++) {
            name = name + adjuctives[adjuctivesDistribtions(generator)] + " ";
        }
        switch(oneInThree(generator)) {
            case NAME_CASE:
                // Adjuctives and names seems like a dangerous duo. 
                name = "";
                name = name + names[nameDistribtions(generator)] + " ";
            break;
            case ANIMAL_CASE:
                name = name + animals[animalDistribtions(generator)] + " ";
            break;
            case OBJECT_CASE:
                name = name + things[thingDistribtions(generator)] + " ";
            break;
        }
        return name;
    }
};

#endif