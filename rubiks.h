#ifndef RUBIKS_H
#define RUBIKS_H

#include <ostream>

#define SOLUTION_MAX 25 // size of array to expect
#define N_COLORS 6
#define CUBE_N 3

typedef enum {WHITE, YELLOW, RED, ORANGE, BLUE, GREEN, NO_COLOR} Color;
enum class Turn {Clk, CntrClk};
typedef struct {
    Color face;
    Turn direction;
} Move;
typedef enum {Random} SolveMethod;

class Rubiks {
public:
    Rubiks();
    bool interactiveSet(bool quick = true);
    bool checkValid();
    bool isSolved();
    size_t score(SolveMethod method) const;
    void executeTurn(Color side, Turn direction);
    void turn180(Color side);
    std::string toString() const;
    std::string asArray() const;
    std::string face(Color face) const;
    Color voxel(Color face, int i, int j) const;
private:
    Color cube[N_COLORS-1][N_COLORS-1][N_COLORS-1];
    Color *refSquare(Color face, int i, int j);
};

Color toColor(std::string userColor);
std::string color_as_str(Color color);
std::ostream& operator<<(std::ostream& os, const Color obj);
std::ostream& operator<<(std::ostream& os, const Turn obj);
std::ostream& operator<<(std::ostream& os, const Rubiks obj);
std::ostream& operator<<(std::ostream& os, const Move obj);
Turn operator!(Turn obj);
bool solve(Rubiks& cube, Move *solution, SolveMethod method, size_t max_moves = 8);

#endif
