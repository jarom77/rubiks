#include <iostream>
#include "rubiks.h"

int main() {
    Rubiks cube;
    
    std::cout << cube << std::endl;

    std::cout << "Cube solved: " << cube.isSolved() << std::endl;
    cube.executeTurn(BLUE, CLK);
    std::cout << "blue clk\n" << cube << std::endl;
    cube.executeTurn(RED, CNTRCLK);
    std::cout << "red cntrclk\n" << cube << std::endl;
    std::cout << cube.face(RED) << std::endl;
    cube.executeTurn(YELLOW, CLK);
    std::cout << "yellow clk\n" << cube << std::endl;
    cube.executeTurn(ORANGE, CLK);
    std::cout << "orange clk\n" << cube << std::endl;
    cube.executeTurn(WHITE, CLK);
    std::cout << "white clk\n" << cube << std::endl;
    cube.executeTurn(RED, CLK);
    std::cout << "red clk\n" << cube << std::endl;
    std::cout << "Cube solved: " << cube.isSolved() << std::endl;

    // now solve

    return 0;
}
