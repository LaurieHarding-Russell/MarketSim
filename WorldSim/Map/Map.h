#ifndef MAP_H
#define MAP_H

#include "Coordinate.h"
#include "Resource.h"
#include <vector>

#include <stdlib.h>
#include <time.h>
#include <stdexcept>

class Map {

    private:
    Coordinate topLeft;
    Coordinate bottomRight;
    std::vector<Resource> resources;
    
    public:

    Map(Coordinate topLeft, Coordinate bottomRight);
    bool validateResourceIsInMap(Resource resource);
    bool validateResourceIsInMap(Coordinate resource);

    std::vector<Resource> getResources();
    void addResource(Resource resource);
};

#endif