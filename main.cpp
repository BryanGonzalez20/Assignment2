#include <iostream>
#include "point.h"
#include "world.h"
#include "robot.h"
using namespace std;

int main() {
    int x;
    int y;

    // Creating an Array that has 3 coin locations ex. (0,0) (0,0) (0,0)
    Point coinLocationArray [3];
    World world;

    for(int i = 0; i < 3; i++){

        cout << "\nEnter a X and a Y value" << endl;
        cin >> x;
        cin >> y;

        // Checking boundaries on X value
        if (x < 0 || x > 9){
            while(x < 0 || x > 9){
                cout << "Please stay in the range for the X value. Try again." << endl;
                cout << "Enter a X value" << endl;
                cin >> x;
            }
        }

        // Checking boundaries on Y value
        if (y < 0 || y > 9){
            while(y < 0 || y > 9){
                cout << "Please stay in the range for the Y value. Try again." << endl;
                cout << "Enter a Y value" << endl;
                cin >> y;
            }
        }

        // Setting the value for 3 different coin locations
        coinLocationArray[i].set(x,y);

        // Reiterating the locations for the user
        cout << "Coordinate " << i+1 << ": " << endl;
        coinLocationArray[i].print();

        // Set the values of the coins with the coin number
        world.set(i, x, y);
    }

    // Print all the coin numbers and the coin locations for user in a nice format
    cout << endl;
    world.print();
    cout << endl;


    // Initialize robot object
    Robot robot;
    robot.init();


    int numMoves = 0;
    int numCoins = 0;

    // Since we cant access the robot's location, we must manually update with these variables
    int robotX = 0;
    int robotY = 0;

    robot.print();
    // COIN CHECK: check if the current robot location is a coin location (specifically 0,0)
    for(int i = 0; i < 3; i++){
        if(robotX == coinLocationArray[i].getX() && robotY == coinLocationArray[i].getY()){
            numCoins++;
            cout << "You've found a coin" << endl;
            if (numCoins == 3){
                cout << "You have found all 3 coins! Thank you for playing" << endl;
                cout << "The robot made " << numMoves << " moves" << endl;
                return 0;
            }
        }
    }


    // Traverse every cell in the grid
    for (int y = 0; y <= 9; y++) { // y is the number of rows

        // Move all the way East
        while (!robot.eastEnd()) {

            robot.forward();
            robotX++; // update X location
            numMoves++;
            robot.print();

            // COIN CHECK: check if the current robot location is a coin location
            for(int i = 0; i < 3; i++){
                if(robotX == coinLocationArray[i].getX() && robotY == coinLocationArray[i].getY()){
                    numCoins++;
                    cout << "You've found a coin" << endl;
                    if (numCoins == 3){
                        cout << "You have found all 3 coins! Thank you for playing" << endl;
                        cout << "The robot made " << numMoves << " moves" << endl;
                        return 0;
                    }
                }
            }
        }

        // Change orientation to West once you've reached the East border. This will zag since were at the east end.
        // (y<9) Prevents from doing zag once you're in the last row
        if (y < 9) {
            robot.zag();
            robotY++; // update Y location
            numMoves++;
            robot.print();

            // COIN CHECK: check if the current robot location is a coin location
            for(int i = 0; i < 3; i++){
                if(robotX == coinLocationArray[i].getX() && robotY == coinLocationArray[i].getY()){
                    numCoins++;
                    cout << "You've found a coin" << endl;
                    if (numCoins == 3){
                        cout << "You have found all 3 coins! Thank you for playing" << endl;
                        cout << "The robot made " << numMoves << " moves" << endl;
                        return 0;
                    }
                }
            }
        }

        // Move all the way West
        while (!robot.westEnd()) {
            robot.forward();
            robotX--; // update X location
            numMoves++;
            robot.print();

            // COIN CHECK: check if the current robot location is a coin location
            for(int i = 0; i < 3; i++){
                if(robotX == coinLocationArray[i].getX() && robotY == coinLocationArray[i].getY()){
                    numCoins++;
                    cout << "You've found a coin" << endl;
                    if (numCoins == 3){
                        cout << "You have found all 3 coins! Thank you for playing" << endl;
                        cout << "The robot made " << numMoves << " moves" << endl;
                        return 0;
                    }
                }
            }
        }

        // Change orientation to East once you've reached the West border. This will zig since were at the west end.
        // (y<9) Prevents from doing zig once you're in the last row
        if (y < 9) {
            robot.zig();
            robotY++; // update Y location
            numMoves++;
            robot.print();

            // COIN CHECK: check if the current robot location is a coin location
            for(int i = 0; i < 3; i++){
                if(robotX == coinLocationArray[i].getX() && robotY == coinLocationArray[i].getY()){
                    numCoins++;
                    cout << "You've found a coin" << endl;
                    if (numCoins == 3){
                        cout << "You have found all 3 coins! Thank you for playing" << endl;
                        cout << "The robot made " << numMoves << " moves" << endl;
                        return 0;
                    }
                }
            }
        }

        // Don't understand why but it works
        if(robot.southEnd()){
            break;
        }
    }



    return 0;
}





/*
    char command;

    cout << "These are the commands:\n\t\n\t";
    cout << "F - move forward one step\n\t"
            "C - turn 90 degrees clockwise\n\t"
            "A - turn 90 degrees anti-clockwise\n\t"
            "Q - Quit\n\t";

    while(command!= 'Q') {

        cout << "Enter a command: ";
        cin >> command;

        switch(command){

            case 'F':
                robot.forward();
                if(robot.getOrientation() == east){
                    robotX++;
                }
                else if(robot.getOrientation() == west){
                    robotX--;
                }
                else if(robot.getOrientation() == north){
                    robotY--;
                }
                else if(robot.getOrientation() == south){
                    robotY++;
                }
                cout << robotX << ", " << robotY << endl;
                numMoves++;
                robot.print();
                // COIN CHECK: check if the current robot location is a coin location (specifically 0,0)
                for(int i = 0; i < 3; i++){
                    if(robotX == coinLocationArray[i].getX() && robotY == coinLocationArray[i].getY()){
                        numCoins++;
                        cout << "You've found a coin" << endl;
                        if (numCoins == 3){
                            cout << "You have found all 3 coins! Thank you for playing" << endl;
                            cout << "The robot made " << numMoves << " moves" << endl;
                            return 0;
                        }
                    }
                }

                if (robot.eastEnd()) {
                    robot.zag();
                    robotY++;
                    cout << robotX << ", " << robotY << endl;
                    numMoves++;
                    robot.print();
                    // COIN CHECK: check if the current robot location is a coin location (specifically 0,0)
                    for(int i = 0; i < 3; i++){
                        if(robotX == coinLocationArray[i].getX() && robotY == coinLocationArray[i].getY()){
                            numCoins++;
                            cout << "You've found a coin" << endl;
                            if (numCoins == 3){
                                cout << "You have found all 3 coins! Thank you for playing" << endl;
                                cout << "The robot made " << numMoves << " moves" << endl;
                                return 0;
                            }
                        }
                    }
                    break;
                }

                if(robot.westEnd()){
                    robot.zig();
                    robotY++;
                    cout << robotX << ", " << robotY << endl;
                    numMoves++;
                    robot.print();
                    // COIN CHECK: check if the current robot location is a coin location (specifically 0,0)
                    for(int i = 0; i < 3; i++){
                        if(robotX == coinLocationArray[i].getX() && robotY == coinLocationArray[i].getY()){
                            numCoins++;
                            cout << "You've found a coin" << endl;
                            if (numCoins == 3){
                                cout << "You have found all 3 coins! Thank you for playing" << endl;
                                cout << "The robot made " << numMoves << " moves" << endl;
                                return 0;
                            }
                        }
                    }
                    break;
                }

                break;



            case 'C':
                robot.turnCW();
                robot.print();
                break;

            case 'A':
                robot.turnAntiCW();
                robot.print();
                break;

            case 'Q':
                cout << "Thank you for playing" << endl;
                break;

            default:
                cout << "You have not provided one of the given options. Try again." << endl;

        }

    }


*/




















    /*

    robot.print();
    // COIN CHECK: check if the current robot location is a coin location (specifically 0,0)
    for(int i = 0; i < 3; i++){
        if(robotX == coinLocationArray[i].getX() && robotY == coinLocationArray[i].getY()){
            numCoins++;
            cout << "You've found a coin" << endl;
            if (numCoins == 3){
                cout << "You have found all 3 coins! Thank you for playing" << endl;
                cout << "The robot made " << numMoves << " moves" << endl;
                return 0;
            }
        }
    }


    // Traverse every cell in the grid
    for (int y = 0; y <= 9; y++) { // y is the number of rows

        // Move all the way East
        while (!robot.eastEnd()) {

            robot.forward();
            robotX++; // update X location
            numMoves++;
            robot.print();

            // COIN CHECK: check if the current robot location is a coin location
            for(int i = 0; i < 3; i++){
                if(robotX == coinLocationArray[i].getX() && robotY == coinLocationArray[i].getY()){
                    numCoins++;
                    cout << "You've found a coin" << endl;
                    if (numCoins == 3){
                        cout << "You have found all 3 coins! Thank you for playing" << endl;
                        cout << "The robot made " << numMoves << " moves" << endl;
                        return 0;
                    }
                }
            }
        }

        // Change orientation to West once you've reached the East border. This will zag since were at the east end.
        // (y<9) Prevents from doing zag once you're in the last row
        if (y < 9) {
            robot.zag();
            robotY++; // update Y location
            numMoves++;
            robot.print();

            // COIN CHECK: check if the current robot location is a coin location
            for(int i = 0; i < 3; i++){
                if(robotX == coinLocationArray[i].getX() && robotY == coinLocationArray[i].getY()){
                    numCoins++;
                    cout << "You've found a coin" << endl;
                    if (numCoins == 3){
                        cout << "You have found all 3 coins! Thank you for playing" << endl;
                        cout << "The robot made " << numMoves << " moves" << endl;
                        return 0;
                    }
                }
            }
        }

        // Move all the way West
        while (!robot.westEnd()) {
            robot.forward();
            robotX--; // update X location
            numMoves++;
            robot.print();

            // COIN CHECK: check if the current robot location is a coin location
            for(int i = 0; i < 3; i++){
                if(robotX == coinLocationArray[i].getX() && robotY == coinLocationArray[i].getY()){
                    numCoins++;
                    cout << "You've found a coin" << endl;
                    if (numCoins == 3){
                        cout << "You have found all 3 coins! Thank you for playing" << endl;
                        cout << "The robot made " << numMoves << " moves" << endl;
                        return 0;
                    }
                }
            }
        }

        // Change orientation to East once you've reached the West border. This will zig since were at the west end.
        // (y<9) Prevents from doing zig once you're in the last row
        if (y < 9) {
            robot.zig();
            robotY++; // update Y location
            numMoves++;
            robot.print();

            // COIN CHECK: check if the current robot location is a coin location
            for(int i = 0; i < 3; i++){
                if(robotX == coinLocationArray[i].getX() && robotY == coinLocationArray[i].getY()){
                    numCoins++;
                    cout << "You've found a coin" << endl;
                    if (numCoins == 3){
                        cout << "You have found all 3 coins! Thank you for playing" << endl;
                        cout << "The robot made " << numMoves << " moves" << endl;
                        return 0;
                    }
                }
            }
        }

        // Don't understand why but it works
        if(robot.southEnd()){
            break;
        }
    }



    return 0;
}

*/
