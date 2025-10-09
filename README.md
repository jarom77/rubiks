# Virtual Rubiks Cube

This repository allows you to play with a Rubiks cube in your command line! What could be more fun than a virtual Rubiks cube in the terminal?

## Goal

Fork the repo and write your own solver. If you use a paper or other source, cite it as a comment in your code. When you have a working solution, submit a pull request.

### Testing

Test your solution by running `make`. It will run your solution with three different cubes of increasing difficulty.

### Writing a Solution

This is done by modifying `rubiks_solve.cpp` and `rubiks.h`. For example, to add your solver "Enigma", you'd add it as a solve method in `rubiks.h` on line 14:

```c++
typedef enum {Enigma, Basic} SolveMethod;
```

**Important!!** Be sure to add your method at the beginning of the list! (so it's the first one listed.) Otherwise you'll have to tweak other scripts.

Then you add it to `rubiks_solve.cpp`:

```c++
bool solve_enigma(Rubiks& cube, Move *solution) {
    // solve it!
    return cube.isSolved();
}

bool solve(Rubiks& cube, Move *solution, SolveMethod method, size_t max_moves) {
    if (method == Basic)
        return solve_basic(cube, solution, max_moves);
    if (method == Enigma)
        return solve_enigma(cube, solution);
    return false;
}
```

## Notes

The Rubiks cube is a class. Member function descriptions are in the header file.

All 2D representations of a side are oriented with white on top. For white and yellow, red is on top. When inputting a cube side in `interactiveSet`, input in reading order (left-to-right, then down).

The iterator classes will save you a lot of time. They provide ways to iterate through both colors and move types.

MoveIter not only iterates through the 13 possible moves (includes null move at end), but it executes the moves on the cube provided (and undoes them before the next move). It will speed things up.

**Important!!** When building the solution from your solver, there are two things to be careful of.

1. The length of `solution`, which is an array of Moves, is defined in `rubiks.h` as `SOLUTION_MAX = 25`. Don't put in more than 25 moves.
2. Your solution must end with a `NO_COLOR` move. This is a non-move, or null move, that marks the end of your solution (like a NULL in a C-string).

### Hints

- Everything here is shown in the `solve_basic` solver in `rubiks_solver.cpp`.
- Run `make main` and then `./main N`, replacing N with a number. This will do N random turns on a cube, then try to solve it. This allows you more practice scenarios.
  - You'll find that `solve_basic` can solve cubes with only 1 turn (`./main 1`), but can't solve anything more complex.
