#ifndef MAP_H
#define MAP_H

#include "Coordinate.h"
#include "Resource.h"
#include <vector>

#include <stdlib.h>
#include <time.h>

class Map {

    private:
    Coordinate topLeft;
    Coordinate bottomRight;
    std::vector<Resource> resources;
    
    public:

    Map();

    std::vector<Resource> getResources() {
        return resources;
    }

    static Map generateMap(Coordinate topLeft, Coordinate bottomRight) {
        Map map = Map();
        map.topLeft = topLeft;
        map.bottomRight = bottomRight;

        srand (time(NULL));
        int numberOfResources = rand() % 1000 + 500;

        for (int i = 0; i != numberOfResources; i++) {
            map.resources.push_back(Resource());
        }
        return map;
    }
};

#endif