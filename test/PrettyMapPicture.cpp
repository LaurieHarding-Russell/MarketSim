#include <Map.h>

int main() {
    Map worldMap = Map(
        Coordinate().setX(0.0).setY(0.0),
        Coordinate().setX(100.0).setY(100.0)
    );

    worldMap.getTopLeft();
    worldMap.getBottomRight();

}