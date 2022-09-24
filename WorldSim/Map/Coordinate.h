#ifndef COORDINATE_H
#define COORDINATE_H

class Coordinate {
    private:
    double x;
    double y;

    public:
    double getX();
    double getY();

    Coordinate setX(double x);
    Coordinate setY(double y);

};

#endif