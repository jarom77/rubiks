#include "rubiks.h"
#include <iostream>
#include <string>
#include <cctype>

bool Rubiks::interactiveSet() {
    std::string userColor;
    for (size_t x = 0; x < 5; x++) for (size_t y = 0; y < 5; y++)
        for (size_t z = 0; z < 5; z++) cube[x][y][z] = NO_COLOR;
    std::cout << "White side up, otherwise red up\n";
    for (ColorIter i; !i.atEnd(); i++) {
        std::cout << i << " side:\n";
        for (size_t j = 0; j < CUBE_N; j++)
            for (size_t k = 0; k < CUBE_N; k++) {
                std::cin >> userColor;
                *refSquare(i.getColor(),j,k) = toColor(userColor);
            }
    }

    return checkValid();
}

/* Return pointer to square in cube
 *
 * W: z,  y,  x
 * Y: z, -y,  x
 * R: x,  z, -y
 * O: x,  z,  y
 * B: y,  z,  x
 * G: y,  z, -x
*/
Color *Rubiks::refSquare(Color face, size_t i, size_t j) {
    size_t x, y, z;
    size_t *pri, *sec, *ter; // dimension specs
    
    // set dimensions
    sec = &z; ter = &x;
    switch (face) {
        case WHITE:
        case YELLOW:
            pri = &z;
            sec = &y;
            break;
        case RED:
        case ORANGE:
            pri = &x;
            ter = &y;
            break;
        case BLUE:
        case GREEN:
            pri = &y;
            break;
        default:
            return NULL;
    }

    // set depth
    if (face == WHITE || face == RED || face == BLUE) {
        *pri = 0;
    } else *pri = CUBE_N + 1;

    // assign grid
    *sec = i + 1;
    *ter = j + 1;

    // invert axes
    if (face == YELLOW || face == RED || face == GREEN)
        *ter = -*ter + CUBE_N + 1;
    else if (face == YELLOW) *sec = -*sec + CUBE_N + 1;

    return &(cube[x][y][z]);
}

bool Rubiks::checkValid() {
    for (ColorIter i; !i.atEnd(); i++)
        if (*(refSquare(i.getColor(),1,1)) != i.getColor()) {
            std::cerr << "Invalid center on " << i.getColor() << " face! Exiting.\n";
            return false;
        }
    return true;
}
