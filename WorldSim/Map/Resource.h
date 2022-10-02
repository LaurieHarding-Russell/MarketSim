#ifndef RESOURCE_H
#define RESOURCE_H

#include "Coordinate.h"
#include <string>
#include <stdexcept>

// FIXME, might want to rename
class Resource {
    public:
    virtual std::string getType() { 
        throw std::invalid_argument( "Unimplemented getType" );
    }

    virtual Coordinate getCoordinate() {
        throw std::invalid_argument( "Unimplemented getCoordinate" );
    }
};
#endif