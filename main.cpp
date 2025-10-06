#include <iostream>
#include "rubiks.h"

int main() {
    Rubiks cube;
    
    if (!cube.interactiveSet()) return 1;

    std::cout << cube;

    // now solve

    return 0;
}
