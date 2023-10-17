#ifndef POINT_H
#define POINT_H
#include <iostream>
using namespace std;


class Point{
private:
    int x;
    int y;

public:
    Point();
    void print() const;
    void set(int x, int y);
    int getX();
    int getY();



};





#endif