//
// Created by Dell on 17-05-2023.
//

#ifndef GenCubeSOLVER_GENCUBE_H
#define GenCubeSOLVER_GENCUBE_H

#include<bits/stdc++.h>
using namespace std;


class GenCube {
public:
    enum class FACE {
        UP,
        LEFT,
        FRONT,
        RIGHT,
        BACK,
        DOWN
    };

    enum class COLOR {
        WHITE,
        GREEN,
        RED,
        BLUE,
        ORANGE,
        YELLOW
    };

    enum class MOVE {
        L,LPRIME, L2,
        R, RPRIME, R2,
        U, UPRIME, U2,
        D, DPRIME, D2,
        F, FPRIME, F2,
        B, BPRIME, B2
    };
    //Returns the color of the cell at (row, col) in face.
    virtual COLOR getColor(FACE face, unsigned row, unsigned col) const = 0;  //pure virtual function


    // Returns the first letter of the given COLOR

    static char getColorLetter(COLOR color);

    //Returns true if the Rubik Cube is solved, otherwise returns false.

    virtual bool isSolved() const = 0;

    //Returns the move in the string format.

    static string getMove(MOVE ind);

    //print the cube in planer format
    void print() const;

    //randomly shuffle the cube
    vector<MOVE> randomShuffleCube(unsigned int times);


    //perform the moves on the cube
    GenCube &move(MOVE ind);

    //invert the move
    GenCube &invert(MOVE ind);


    //ALL THE 18 MOVES POSSIBLE
    virtual GenCube &f() = 0;

    virtual GenCube &fPrime() = 0;

    virtual GenCube &f2() = 0;

    virtual GenCube &u() = 0;

    virtual GenCube &uPrime() = 0;

    virtual GenCube &u2() = 0;

    virtual GenCube &l() = 0;

    virtual GenCube &lPrime() = 0;

    virtual GenCube &l2() = 0;

    virtual GenCube &r() = 0;

    virtual GenCube &d() = 0;

    virtual GenCube &dPrime() = 0;

    virtual GenCube &d2() = 0;

    virtual GenCube &rPrime() = 0;

    virtual GenCube &r2() = 0;

    virtual GenCube &b() = 0;

    virtual GenCube &bPrime() = 0;

    virtual GenCube &b2() = 0;


    string getCornerColorString(uint8_t ind) const;

    uint8_t getCornerIndex(uint8_t ind) const;

    uint8_t getCornerOrientation(uint8_t ind) const;

};








#endif //GenCubeSOLVER_GENCUBE_H
