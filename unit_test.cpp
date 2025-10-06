#include <iostream>
#include "rubiks.h"

int main() {
    Rubiks cube;
    
    if (!cube.interactiveSet()) return 1;

    std::cout << cube;

    std::cout << cube.asArray();

    // now solve

    return 0;
}
