#ifndef RUBIKS_ITERATORS_H
#define RUBIKS_ITERATORS_H

#include "rubiks.h"

class ColorIter {
public:
    ColorIter() { index = (Color)0; }
    bool atEnd() const { return index == NO_COLOR; }
    Color getColor() const { return index; }
    ColorIter operator++(int);
private:
    Color index;
};

class MoveIter {
public:
    MoveIter();
    MoveIter(Rubiks& cube);
    bool atEnd() const;
    Color getFace() const;
    Turn getDir() const;
    Move getMove() const;
    MoveIter operator++(int);
    size_t score(SolveMethod method) const;
private:
    Rubiks *cube;
    ColorIter face;
    Turn direction;
};

std::ostream& operator<<(std::ostream& os, const ColorIter obj);

#endif
