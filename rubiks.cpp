#include "rubiks.h"
#include <iostream>
#include <string>
#include <cctype>

bool Rubiks::interactiveSet(bool quick) {
    std::string userColor;
    char quickColor;
    Color newColor;
    for (size_t x = 0; x < 5; x++) for (size_t y = 0; y < 5; y++)
        for (size_t z = 0; z < 5; z++) cube[x][y][z] = NO_COLOR;
    std::cout << "White side up, otherwise red up\n";
    for (ColorIter i; !i.atEnd(); i++) {
        std::cout << i << " side:\n";
        for (size_t j = 0; j < CUBE_N; j++)
            for (size_t k = 0; k < CUBE_N; k++) {
                if (quick) {
                    std::cin >> quickColor;
                    newColor = toColor(&quickColor);
                } else {
                    std::cin >> userColor;
                    newColor = toColor(userColor);
                }
                *refSquare(i.getColor(),j,k) = newColor;
            }
    }

    return checkValid();
}

void Rubiks::executeTurn(Color side, Turn direction) {
    int x, y;
    Color last, *last_square, temp;
    for (int i = 1; i <= 2; i++)
        for (int j = -i + 1; j <= 1; j++) {
            x = j; y = i;
            last = *refSquare(side, x+1, y+1);
            for (size_t turn_count = 0; turn_count < 4; turn_count++) {
                // advance turn
                int temp_i = x;
                if (direction == CNTRCLK) {
                    x = -y; y = temp_i;
                } else {
                    x = y; y = -temp_i;
                }

                temp = last;
                last_square = refSquare(side, x+1, y+1);
                last = *last_square;
                *last_square = temp;
            }
        }
}

/* Return pointer to square in cube
 *
 * W: z,  x,  y
 * Y: z,  x, -y
 * R: x,  z, -y
 * O: x,  z,  y
 * B: y,  z,  x
 * G: y,  z, -x
*/
Color *Rubiks::refSquare(Color face, int i, int j) {
    if (i < -1 or j < -1 or i > 3 or j > 3) {
            std::cerr << "Bad dimension! (" << i << ',' << 'j' << ")\n";
            return NULL;
    }
    size_t x, y, z;
    size_t *pri, *sec, *ter; // dimension specs
    
    // set dimensions
    sec = &z; ter = &y;
    switch (face) {
        case WHITE:
        case YELLOW:
            pri = &z;
            sec = &x;
            break;
        case RED:
        case ORANGE:
            pri = &x;
            break;
        case BLUE:
        case GREEN:
            pri = &y;
	    ter = &x;
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

    // allow selection of edges
    if (i < 0 or i >= CUBE_N or j < 0 or j >= CUBE_N) {
        if (*pri == 0) (*pri)++;
        else (*pri)--;
    }

    // invert axes
    if (face == YELLOW || face == RED || face == GREEN)
        *ter = -*ter + CUBE_N + 1;

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
