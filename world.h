#ifndef WORLD_H
#define WORLD_H
#include "point.h"

class World{
private:
    Point coinLocations[3];
public:
    World();
    void print() const;
    void set(int i, int x, int y);
};


#endif