#include "rubiks.h"
#include <iostream>
#include <string>
#include <sstream>

#define ITERUP(name_) size_t name_ = 1; name_ < 4; name_++
#define ITERDOWN(name_) size_t name_ = 3; name_ > 0; name_--

std::ostream& operator<<(std::ostream& os, const Color obj) {
    switch (obj) {
    case WHITE:
        os << "white";
        break;
    case YELLOW:
        os << "yellow";
        break;
    case RED:
        os << "red";
        break;
    case ORANGE:
        os << "orange";
	break;
    case BLUE:
        os << "blue";
        break;
    case GREEN:
        os << "green";
        break;
    case NO_COLOR:
        os << "error";
    }
    return os;
}

Color toColor(std::string userColor) {
    char firstChar = userColor[0] | 0x60;
    switch (firstChar) {
        case 'w': return WHITE;
        case 'y': return YELLOW;
        case 'r': return RED;
        case 'o': return ORANGE;
        case 'b': return BLUE;
        case 'g': return GREEN;
        default: return NO_COLOR;
    }
}

std::ostream& operator<<(std::ostream& os, const ColorIter obj) {
    os << obj.getColor();
    return os;
}

ColorIter ColorIter::operator++(int) {
    index = (Color)((int)index + 1);
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Rubiks obj) {
    os << obj.toString();
    return os;
}

std::string Rubiks::toString() const {
    char sym[7] = "WYROBG";
    std::ostringstream oss;

    // top: red face
    for (ITERUP(z)) {
        oss << "    ";
        for (ITERDOWN(y))
            oss << sym[(int)cube[0][y][z]];
        oss << std::endl;
    }
    oss << std::endl;

    // middle line
    for (ITERUP(x)) {
        // blue (left)
        for (ITERDOWN(z))
            oss << sym[(int)cube[x][0][z]];
        oss << ' ';
        // white (center)
        for (ITERUP(y))
            oss << sym[(int)cube[x][y][0]];
        oss << ' ';
        // green (right)
        for (ITERUP(z))
            oss << sym[(int)cube[x][4][z]];
        oss << std::endl;
    }
    oss << std::endl;

    // orange
    for (ITERUP(z)) {
        oss << "    ";
        for (ITERUP(y))
            oss << sym[(int)cube[4][y][z]];
        oss << std::endl;
    }
    oss << std::endl;

    // yellow
    for (ITERDOWN(x)) {
        oss << "    ";
        for (ITERUP(y))
            oss << sym[(int)cube[x][y][4]];
        oss << std::endl;
    }
    oss << std::endl;
    return oss.str();
}
