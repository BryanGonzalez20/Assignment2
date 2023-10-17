#include "point.h"

// Constructor
Point::Point(){
    x = 0;
    y = 0;
}

void Point::print() const{
    cout << "X = " << x << endl;
    cout << "Y = " << y << endl;
}
void Point::set(int x, int y){
    this->x = x;
    this->y = y;
}
int Point::getX(){
    return x;
}
int Point::getY(){
    return y;
}

