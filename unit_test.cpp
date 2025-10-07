#include <iostream>
#include "rubiks.h"

int main() {
    Rubiks cube;
    
    if (!cube.interactiveSet()) return 1;

    std::cout << "\nCube folded out as a net\n\n";
    std::cout << cube;

    std::cout << "\n3D matrix, slices of Z\n";
    std::cout << cube.asArray();

    std::cout << "Green face of cube (with edges)\n\n";
    std::cout << cube.face(GREEN);

    return 0;
}
