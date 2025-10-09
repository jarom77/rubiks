#include <iostream>
#include "rubiks.h"

int main() {
    Rubiks cube;
    
    if (!cube.interactiveSet()) return 1;
    
    std::cout << cube << std::endl;

    Move solution[SOLUTION_MAX];
    if (solve(cube, solution, (SolveMethod)0))
        std::cout << "Solution found!\n";
    else std::cout << "Not solved.\n";

    std::cout << "Steps:\n";
    for (size_t i = 0; solution[i].face != NO_COLOR; i++)
        std::cout << solution[i];
    std::cout << std::endl << cube << "\n\n";

    return 0;
}
