#include "rubiks.h"
#include <iostream>
#include <random>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "Not enough arguments!\nSyntax: " << argv[0] << " <n_turns>\n";
        return 1;
    }

    Rubiks cube;
    // random seed
    srand(time(NULL));
    size_t turns = atoi(argv[1]);
    
    // do some turns
    for (size_t i = 0; i < turns; i++) {
	// choose random face and direction
        Color face = (Color)(rand() % N_COLORS);
        Turn direction = (Turn)(rand() % 2);
        cube.executeTurn(face, direction);
    }

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
