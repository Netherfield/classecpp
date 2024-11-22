/* Copyright 2024 Jacopo Barberis, Netherfield @ github
Software for education purposes, not intended for distribution
*/


#include "rubi.hpp"

map<int, int> Face::edges_init(int s){
    return (s < 3) ? 
        map<int, int>{{(s+1)%6, top}, {(s+2)%6, rht},
                        {(s+4)%6, bot}, {(s+5)%6, lft}}
        : map<int, int>{{(s+5)%6, top}, {(s+4)%6, rht},
                        {(s+2)%6, bot}, {(s+1)%6, lft}};
}

// Initialises the face on side `s`, to the color `color`
Face::Face(int color, int s)
    : f(3, vector<int>(3, color)), side(s), edges(edges_init(s)) {};

// [] returns the pointers of the 3 edge squares to change
Edge Face::operator[](int s){
        Edge edge;
        switch(edges[s])
        {
            //###TODO o sposta l'assegnazione degli edges alla faccia
            // o compila il resto dello switch
            case top:
                edge.e = {&f[0][0], &f[0][1], &f[0][2]};
            case rht:

            case bot:

            case lft:
        }; // restituisce top, rht, bot o lft
}




// Initialises cube to 6 faces with default colors
Cube::Cube()
    : c {Face(blue, Lx), Face(white, Ux), Face(orange, Fx),
        Face(yellow, Dx), Face(green, Rx), Face(red, Bx)} {};

// Rotation can be any integer and will correspond to 1, 2 or 3 clockwise 90 degrees turns
Cube& Cube::rotL(int r){
    // Edge e = c[Fx][Lx];
    // Edge tmp = c[Dx][Lx];
    // c[Dx][Lx] = e;

    // c[Fx].edgeL = c[Ux].edgeL;

    return *this;
}


int main(){
    Cube c;
    c.rotL(3);
}





















