#include <iostream>
#include <string>

#include "Support/support.h"
#include "Maze/maze.h"

int main() {
    Maze maze;
    std::cout
            << "To generate a labyrinth, please enter its defaultWidth x defaultHeight (example 7 x 3).\nThe default is 5 x 5.\nInput : ";
    std::string input;
    std::getline(std::cin, input);

    findWidthAndHeight(&input, &maze);
    std::cout << "\n" << maze.get_width() << " x " << maze.get_height() << "\n";


    system("PAUSE");

    return 0;
}
