#include "rubiks.h"
#include "rubiksIterators.h"

bool solve_basic(Rubiks& cube, Move *solution) {
    // solve
    return false;
}

bool solve(Rubiks& cube, Move *solution, SolveMethod method, size_t max_moves) {
    if (method == Basic)
        return solve_basic(cube, solution);
    return false;
}
