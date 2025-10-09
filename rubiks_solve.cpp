#include "rubiks.h"
#include "rubiksIterators.h"

// try each turn to see if it solves the cube. Then give up.
bool solve_basic(Rubiks& cube, Move *solution) {
    int index = 0;
    for (MoveIter i = MoveIter(cube); !i.atEnd(); i++) {
        if (cube.isSolved()) {
            solution[index] = i.getMove();
            index++;
            break;
        }
    }
    solution[index] = Move{NO_COLOR};
    return cube.isSolved();
}

bool solve(Rubiks& cube, Move *solution, SolveMethod method, size_t max_moves) {
    if (method == Basic)
        return solve_basic(cube, solution);
    solution[0] = Move{NO_COLOR};
    return false;
}
