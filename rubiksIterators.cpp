#include "rubiksIterators.h"

std::ostream& operator<<(std::ostream& os, const ColorIter obj) {
    os << color_as_str(obj.getColor());
    return os;
}

std::ostream& operator<<(std::ostream& os, const Turn obj) {
    if (obj == Turn::Clk) os << "clockwise";
    else os << "counterclockwise";
    return os;
}

Turn operator!(Turn obj) {
    if (obj == Turn::Clk) return Turn::CntrClk;
    return Turn::Clk;
}

ColorIter ColorIter::operator++(int) {
    index = (Color)((int)index + 1);
    return *this;
}

MoveIter::MoveIter() {
    cube = NULL;
}

MoveIter::MoveIter(Rubiks& cube) {
    this->cube = &cube;
    direction = Turn::CntrClk;
    this->cube->executeTurn(face.getColor(), direction);
}

bool MoveIter::atEnd() const {
    return face.atEnd() && direction == Turn::Clk;
}

size_t MoveIter::score(SolveMethod method) const {
    return cube->score(method);
}

Color MoveIter::getFace() const {
    return face.getColor();
}

Turn MoveIter::getDir() const {
    return direction;
}

Move MoveIter::getMove() const {
    return Move{getFace(), getDir()};
}

MoveIter MoveIter::operator++(int) {
    direction = !direction;
    if (direction == Turn::CntrClk) { // CntrClk is first
        // reset cube to original condition
        cube->executeTurn(face.getColor(), direction);

        face++;
        cube->executeTurn(face.getColor(), direction);
    } else cube->turn180(face.getColor());
    return *this;
}
