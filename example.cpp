#include "rubiks.h"
#include <iostream>
#include <random>

using namespace std;

#define EXAMPLE_TURNS 4

int main() {
    Rubiks cube;
    // random seed
    srand(time(NULL));
    
    // do some turns
    for (int i = 0; i < EXAMPLE_TURNS; i++) {
	// choose random face and direction
        Color face = (Color)(rand() % N_COLORS);
        Turn direction = (Turn)(rand() % 2);
        cube.executeTurn(face, direction);
    }

    cout << "Cube folded out as a net\n\n";
    cout << cube << endl;

    cout << "Green face of cube (with edges)\n\n";
    cout << cube.face(GREEN) << endl;

    cout << "Turn green face counter-clockwise\n\n";
    cube.executeTurn(GREEN, Turn::CntrClk);
    cout << cube << endl;

    cout << "Bottom-right blue corner\n";
    Color corner = cube.voxel(BLUE, 2, 2);
    cout << color_as_str(corner) << " " << corner << endl;

    return 0;
}
