/* Copyright 2024 Jacopo Barberis, Netherfield @ github
Software for education purposes, not intended for distribution
*/


#include <vector>
#include <map>
//io
#include <iostream>
#include <fstream>


using namespace std;

typedef struct Edge{
    Edge() : e(3){};
    vector<int*> e;
};

class Face{
    enum Edges {top, rht, bot, lft};

    public:
    Face(int, int);

    // Face& rot(int);
    Edge operator[](int);

    private:
    map<int, int> edges_init(int);

    vector<vector<int>> f;
    int const side;
    map<int, int> edges;

};

class Cube{
    //       1 Ux   
    //  0 Lx 2 Fx 3 Rx 5 Bx
    //       4 Dx
    enum Color {blue, white, orange, green, yellow, red};
    // this order makes indices modular and paired 0-2 3-5
    enum Faces { Lx, Ux, Fx, Rx, Dx, Bx };
    
    public:
    Cube();


    Cube& rotL(int); // turn the front of 1, 2, 3 or -1, -2, -3 (=1) around L
    // Cube& rotU(int); // ...

    

    private:
    // vettore di 6 matrici 3x3
    vector<Face> c;


};



































