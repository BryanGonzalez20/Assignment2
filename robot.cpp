#include "robot.h"

// Constructor
Robot::Robot():
    currentOrientation(north){
    currentLocation.set(0,0);
}


void Robot::init(){
    // currentLocation is a point object so it can hold a coordinate ex. (0,0)
    currentLocation.set(0,0);
    // currentOrientation is an enum data type so it can be any of the directions we listed
    currentOrientation = east;
}

void Robot::print() const{
    // This is a print const function so we cannot directly access the robots location
    // by doing currentLocation.getX() . Instead, we must create a copy and get the location
    // using the copy.                 ex. robotLocation.getX()
    Point robotLocation = currentLocation;
    cout << "I am at (" << robotLocation.getX() << ", " << robotLocation.getY() << ") and I am facing ";

    // This is so we dont get a numerical value for the enum variables
    switch(currentOrientation){
        case north:
            cout << "north";
            break;
        case south:
            cout << "south";
            break;
        case east:
            cout << "east";
            break;
        case west:
            cout << "west";
            break;
        default:
            cout << "error";
            break;
    }
    cout << endl;
}

void Robot::setOrientation(orientation_type orientation){
    currentOrientation = orientation;
}


bool Robot::forward(){

    // might be only up to 8 because 9+1 = 10, so 8+1 means max is 9
    if(currentOrientation == east && currentLocation.getX() <= 8){
        currentLocation.set(currentLocation.getX() + 1, currentLocation.getY());
        return true;
    }
    else if(currentOrientation == west && currentLocation.getX() >= 1){
        currentLocation.set(currentLocation.getX() - 1, currentLocation.getY());
        return true;
    }
    else if(currentOrientation == north && currentLocation.getY() >= 1){
        currentLocation.set(currentLocation.getX(), currentLocation.getY() - 1);
        return true;
    }
    else if(currentOrientation == south && currentLocation.getY() <= 8){
        currentLocation.set(currentLocation.getX(), currentLocation.getY() + 1);
        return true;
    }
    else{
        cout << "You are at the edge of the world" << endl;
        return false;
    }
}


void Robot::turnCW(){
    if(currentOrientation == north){
        currentOrientation = east;
    }
    else if(currentOrientation == east){
        currentOrientation = south;
    }
    else if(currentOrientation == south){
        currentOrientation = west;
    }
    else if(currentOrientation == west){
        currentOrientation = north;
    }
}

void Robot::turnAntiCW(){
    if(currentOrientation == north){
        currentOrientation = west;
    }
    else if(currentOrientation == west){
        currentOrientation = south;
    }
    else if(currentOrientation == south){
        currentOrientation = east;
    }
    else if(currentOrientation == east){
        currentOrientation = north;
    }
}

bool Robot::northEnd(){
    if(currentLocation.getY() == 0){
        return true;
    }
}

bool Robot::southEnd(){
    if(currentLocation.getY() == 9){
        return true;
    }
}

bool Robot::eastEnd(){
    if(currentLocation.getX() == 9){
        return true;
    }
}

bool Robot::westEnd(){
    if(currentLocation.getX() == 0){
        return true;
    }
}

bool Robot::zag(){ // good
    if(currentOrientation == east && eastEnd() == true){
        turnCW();
        forward();
        turnCW();
        return true;
    }
    return false;
}

bool Robot::zig(){ // good
    if(currentOrientation == west && westEnd() == true){
        turnAntiCW();
        forward();
        turnAntiCW();
        return true;
    }
    return false;
}

/*
// added function
orientation_type Robot::getOrientation(){
    return currentOrientation;
}
*/




