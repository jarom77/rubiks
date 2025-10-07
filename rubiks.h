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
    std::string face(Color face) const;
    Color voxel(Color face, int i, int j) const;
private:
    Color cube[N_COLORS-1][N_COLORS-1][N_COLORS-1];
    Color *refSquare(Color face, int i, int j);
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
std::string color_as_str(Color color);
std::ostream& operator<<(std::ostream& os, const Rubiks obj);
std::ostream& operator<<(std::ostream& os, const Color obj);
std::ostream& operator<<(std::ostream& os, const ColorIter obj);
