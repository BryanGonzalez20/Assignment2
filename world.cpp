#include "world.h"


// Constructor sets values of coinLocations coordinates array all to (0,0)
World::World(){
    for(int i = 0; i < 3; i++){
        coinLocations[i] = Point();
    }
};

// Print location of the coins
/*
   The value of Point coin is being updated with the values of coinLocations[i] for each iteration,
   representing the new coins value, so we can access it. We have to take this route because were
   working with a const print function that doesn't allow us to do coinLocations[i].getX() directly.
*/

void World::print() const{
    for(int i = 0; i < 3; i++){
        Point coin = coinLocations[i];
        cout << "Location of coin " << i+1 << ": (" << coin.getX() << ", " << coin.getY() << ")" << endl;
    }
}

// Set the coin number with the coordinates
void World::set(int i, int x, int y){
    if (i >= 0 && i < 3 ){
        coinLocations[i].set(x,y);
    }

}





/*
// Constructor
World::World(){
    for(int i = 0; i < 3; i++){
        Point coin = coinLocations[i];
        coin.set(0,0);
    }

};
*/



/*
// This doesn't work because it is a const print function, otherwise this is a good solution
void World::print() const{
    for(int i = 0; i < 3; i++){
        cout << "Location of coin " << i+1 << ": (" << coinLocations[i].getX() << ", " << coinLocations[i].getY() << ")" << endl;
    }
}
*/