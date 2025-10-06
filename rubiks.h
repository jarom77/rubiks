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
    std::string toString() const;
    std::string asArray() const;
private:
    Color cube[N_COLORS-1][N_COLORS-1][N_COLORS-1];
    Color *refSquare(Color face, size_t i, size_t j);
    std::string voxel(size_t x,size_t y,size_t z) const;
};

class ColorIter {
public:
    ColorIter() { index = (Color)0; }
    bool atEnd() { return index == NO_COLOR; }
    Color getColor() const { return index; }
    ColorIter operator++(int);
private:
    Color index;
};

Color toColor(std::string userColor);
std::ostream& operator<<(std::ostream& os, const Rubiks obj);
std::ostream& operator<<(std::ostream& os, const Color obj);
std::ostream& operator<<(std::ostream& os, const ColorIter obj);
