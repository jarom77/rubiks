#include "rubiks.h"
#include "rubiksIterators.h"
#include <iostream>
#include <string>
#include <sstream>

#define ITERUP(name_) size_t name_ = 1; name_ < 4; name_++
#define ITERDOWN(name_) size_t name_ = 3; name_ > 0; name_--

std::ostream& operator<<(std::ostream& os, const Color obj) {
    std::string sym[7] = {
        "\e[107;30m  \e[0m",
        "\e[30;48:5:226m  \e[0m",
        "\e[101m  \e[0m",
        "\e[48:5:214m  \e[0m",
        "\e[104m  \e[0m",
        "\e[102m  \e[0m",
        "  "
    };
    os << sym[(int)obj];
    return os;
}

std::string color_as_str(Color color) {
    std::string lookup[7] = {
        "white",
        "yellow",
        "red",
        "orange",
        "blue",
        "green",
        "blank"
    };
    return lookup[(int)color];
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

std::ostream& operator<<(std::ostream& os, const Turn obj) {
    if (obj == Turn::Clk) os << "clockwise";
    else os << "counterclockwise";
    return os;
}

Turn operator!(Turn obj) {
    if (obj == Turn::Clk) return Turn::CntrClk;
    return Turn::Clk;
}

std::ostream& operator<<(std::ostream& os, const Move obj) {
    os << color_as_str(obj.face) << ' ' << obj.direction << std::endl;
    return os;
}

std::ostream& operator<<(std::ostream& os, const Rubiks obj) {
    os << obj.toString();
    return os;
}

std::string Rubiks::face(Color face) const {
    std::ostringstream oss;
    for (int i = -1; i < 4; i++) {
        for (int j = -1; j < 4; j++)
            oss << voxel(face, i, j);
        oss << std::endl;
    }
    return oss.str();
}

Color Rubiks::voxel(Color face, int i, int j) const {
    return *(const_cast<Rubiks*>(this)->refSquare(face, i, j));
}

std::string Rubiks::toString() const {
    std::ostringstream oss, blank;
    for (size_t i = 0; i < 4; i++) blank << NO_COLOR;
    const std::string BLANK_FACE = blank.str();

    // top: red face
    for (ITERDOWN(z)) {
        oss << BLANK_FACE;
        for (ITERUP(y))
            oss << cube[0][y][z];
        oss << std::endl;
    }
    oss << std::endl;

    // middle line
    for (ITERUP(x)) {
        // blue (left)
        for (ITERDOWN(z))
            oss << cube[x][0][z];
        oss << NO_COLOR;
        // white (center)
        for (ITERUP(y))
            oss << cube[x][y][0];
        oss << NO_COLOR;
        // green (right)
        for (ITERUP(z))
            oss << cube[x][4][z];
        oss << std::endl;
    }
    oss << std::endl;

    // orange
    for (ITERUP(z)) {
        oss << BLANK_FACE;
        for (ITERUP(y))
            oss << cube[4][y][z];
        oss << std::endl;
    }
    oss << std::endl;

    // yellow
    for (ITERDOWN(x)) {
        oss << BLANK_FACE;
        for (ITERUP(y))
            oss << cube[x][y][4];
        oss << std::endl;
    }
    oss << std::endl;
    return oss.str();
}

std::string Rubiks::strSpec() const {
    std::string spec = "";
    for (ColorIter face; !face.atEnd(); face++)
        for (size_t i = 0; i < CUBE_N; i++)
            for (size_t j = 0; j < CUBE_N; j++)
                spec += color_as_str(voxel(face.getColor(), i, j))[0];
    return spec;
}

std::string Rubiks::asArray() const {
    std::ostringstream oss;
    for (size_t z = 0; z < 5; z++) {
        for (size_t x = 0; x < 5; x++) {
            for (size_t y = 0; y < 5; y++)
                oss << cube[x][y][z];
            oss << std::endl;
        }
        oss << std::endl;
    }
    return oss.str();
}
