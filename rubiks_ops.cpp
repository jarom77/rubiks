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

std::string Rubiks::voxel(size_t x,size_t y,size_t z) const {
    std::string sym[7] = {
        "\e[107;30m \e[0m",
        "\e[30;48:5:226m \e[0m",
        "\e[101m \e[0m",
        "\e[48:5:214m \e[0m",
        "\e[104m \e[0m",
        "\e[102m \e[0m",
        " "
    };
    return sym[(int)cube[x][y][z]];
}

std::string Rubiks::toString() const {
    std::ostringstream oss;
    oss << std::endl;

    // top: red face
    for (ITERDOWN(z)) {
        oss << "    ";
        for (ITERUP(y))
            oss << voxel(0,y,z);
        oss << std::endl;
    }
    oss << std::endl;

    // middle line
    for (ITERUP(x)) {
        // blue (left)
        for (ITERDOWN(z))
            oss << voxel(x,0,z);
        oss << ' ';
        // white (center)
        for (ITERUP(y))
            oss << voxel(x,y,0);
        oss << ' ';
        // green (right)
        for (ITERUP(z))
            oss << voxel(x,4,z);
        oss << std::endl;
    }
    oss << std::endl;

    // orange
    for (ITERUP(z)) {
        oss << "    ";
        for (ITERUP(y))
            oss << voxel(4,y,z);
        oss << std::endl;
    }
    oss << std::endl;

    // yellow
    for (ITERDOWN(x)) {
        oss << "    ";
        for (ITERUP(y))
            oss << voxel(x,y,4);
        oss << std::endl;
    }
    oss << std::endl;
    return oss.str();
}

std::string Rubiks::asArray() const {
    std::ostringstream oss;
    for (size_t z = 0; z < 5; z++) {
	    for (size_t x = 0; x < 5; x++) {
            for (size_t y = 0; y < 5; y++)
                oss << voxel(x,y,z);
            oss << std::endl;
        }
        oss << std::endl;
    }
    return oss.str();
}
