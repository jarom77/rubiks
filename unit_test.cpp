#include <iostream>
#include "rubiks.h"

int main() {
    Rubiks cube;
    
    if (!cube.interactiveSet()) return 1;

    std::cout << std::endl;
    std::cout << "3D matrix, slices of Z\n";
    std::cout << cube.asArray();

    std::cout << "Cube folded out as a net\n\n";
    std::cout << cube << std::endl;

    std::cout << "Green face of cube (with edges)\n\n";
    std::cout << cube.face(GREEN) << std::endl;

    std::cout << "Turn green face counter-clockwise\n\n";
    cube.executeTurn(GREEN, Turn::CntrClk);
    std::cout << cube << std::endl;
    return 0;
}
