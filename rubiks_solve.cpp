#include "rubiks.h"
#include "rubiksIterators.h"

bool solve_random(Rubiks& cube, Move *solution, size_t max_moves) {
    // solve
    return false;
}

bool solve(Rubiks& cube, Move *solution, SolveMethod method, size_t max_moves) {
    if (method == Random)
       return solve_random(cube, solution, max_moves);
    return false;
}
