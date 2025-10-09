#include <iostream>
#ifndef MOVE_LOOKAHEAD
#define MOVE_LOOKAHEAD 2
#endif
#include "rubiks.h"

#define LENGTH 10

int main() {
    Rubiks cube;
    std::cout << cube << std::endl;

    std::cout << "Cube solved: " << cube.isSolved() << std::endl;
    std::cout << "Score: " << cube.score() << std::endl;
    cube.executeTurn(BLUE, Turn::Clk);
    std::cout << "blue clk: " << cube.score() << std::endl << cube << std::endl;
    cube.executeTurn(RED, Turn::CntrClk);
    std::cout << "red cntrclk: " << cube.score() << std::endl << cube << std::endl;
    std::cout << cube.face(RED) << std::endl;
    cube.executeTurn(YELLOW, Turn::Clk);
    std::cout << "yellow clk: " << cube.score() << std::endl << cube << std::endl;
    cube.executeTurn(ORANGE, Turn::Clk);
    std::cout << "orange clk: " << cube.score() << std::endl << cube << std::endl;
    cube.executeTurn(WHITE, Turn::Clk);
    std::cout << "white clk: " << cube.score() << std::endl << cube << std::endl;
    cube.executeTurn(RED, Turn::Clk);
    std::cout << "red clk: " << cube.score() << std::endl << cube << std::endl;
    std::cout << "Cube solved: " << cube.isSolved() << "\n\n";

    Move solution[SOLUTION_MAX];
    if (solve(cube, solution, LENGTH, NeighborCost))
        std::cout << "Solution found!\n";
    else std::cout << "Not solved.\n";
    std::cout << "Steps:\n";
    for (size_t i = 0; solution[i].face != NO_COLOR; i++)
        std::cout << solution[i];
    std::cout << std::endl << cube << "\n\n";

    return 0;
}
