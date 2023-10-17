#ifndef ROBOT_H
#define ROBOT_H
#include "point.h"
#include <string>

/*enum orientation_type{
    north, south, east, west
};*/

class Robot{
private:
    Point currentLocation;
    enum orientation_type{
        north, south, east, west
    };
    orientation_type currentOrientation;


public:

    Robot();
    void init();
    void print() const;
    void setOrientation(orientation_type orientation);
    bool forward();
    void turnCW();
    void turnAntiCW();
    bool eastEnd();
    bool westEnd();
    bool northEnd();
    bool southEnd();
    bool zag();
    bool zig();
    //added
    // orientation_type getOrientation();


};



#endif