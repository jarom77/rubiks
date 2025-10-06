#include "rubiks.h"
#include <iostream>
#include <string>
#include <cctype>

bool Rubiks::interactiveSet() {
    std::string userColor;
    std::cout << "White side up, otherwise blue up\n";
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
 * W: z, -x,  y
 * Y: z,  x,  y
 * R: x, -y,  z
 * O: x,  y,  z
 * B: y,  x,  z
 * G: y, -x,  z
*/
Color *Rubiks::refSquare(Color face, size_t i, size_t j) {
    size_t x, y, z;
    size_t *pri, *sec, *ter; // dimension specs
    
    // set dimensions
    sec = &x; ter = &z;
    switch (face) {
        case WHITE:
        case YELLOW:
            pri = &z;
            ter = &y;
            break;
        case RED:
        case ORANGE:
            pri = &x;
            sec = &y;
            break;
        case BLUE:
        case GREEN:
            pri = &y;
            break;
        default:
            return NULL;
    }

    // invert axes, set depth
    if (face == WHITE || face == RED || face == BLUE) {
        *pri = 0;
        *sec = -*sec + CUBE_N - 1;
    } else *pri = N_COLORS - 2;

    // assign grid
    *sec = i + 1;
    *ter = j + 1;

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
