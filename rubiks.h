#include <ostream>

#define N_COLORS 6
#define CUBE_N 3

typedef enum {WHITE, YELLOW, RED, ORANGE, BLUE, GREEN, NO_COLOR} Color;
typedef enum {CLK, CNTRCLK} Turn;

class Rubiks {
public:
    bool interactiveSet();
    bool checkValid();
    void executeTurn(Color side, Turn direction);
    void print();
private:
    Color cube[N_COLORS-1][N_COLORS-1][N_COLORS-1];
    Color *refSquare(Color face, size_t i, size_t j);
};

class ColorIter {
public:
    ColorIter() { index = (Color)0; }
    bool atEnd() { return index == NO_COLOR; }
    Color getColor() const { return index; }
    ColorIter operator++(int) {
        index = (Color)((int)index + 1);
        return *this;
    }
private:
    Color index;
};
