#ifndef NAME_GENERATOR_H
#define NAME_GENERATOR_H

#include <string>
#include <vector>

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
        "Shield",
        "Science",
        "Math",
        "Music",
        "Paper",
        "Robot",
        "Rock",
        "Zombie"
    };

    const std::vector<std::string> adjuctives = {
        "Broken",
        "Computing",
        "Calculating",
        "Cold",
        "Dangerous"
        "Flaming",
        "Giant",
        "Honorable",
        "Hot"
        "Imperial",
        "Infinity",
        "Large",
        "Lucky",
        "Sharp",
        "Small",
        "Unlimited"
    };

    const int MAX_ADJUCTIVES = 2;
    const int MAX_NAMES = 2;

    const int NAME_CASE = 0;
    const int ANIMAL_CASE = 1;
    const int OBJECT_CASE = 2;


    //FIXME, I really hope none of these combos are that terrible...
    // FIXME, probably should make it related to industry etc.
    static std::string corporateNameGenerator() {
        std::string name = "";
        for (int i =0; i < rand() % (MAX_ADJUCTIVES + 1); i++) {
            name = name + adjuctives[rand() % adjuctives.size()] + " ";
        }

        switch(rand() % 3) {
            case NAME_CASE:
                // Adjuctives and names seems like a dangerous duo. 
                name = "";
                name = name + names[rand() % names.size()] + " ";
            break;
            case ANIMAL_CASE:
                name = name + animals[rand() % animals.size()] + " ";
            break;
            case OBJECT_CASE:
                name = name + things[rand() % things.size()] + " ";
            break;
        }

        name.pop_back();
        return name;
    }
};

#endif