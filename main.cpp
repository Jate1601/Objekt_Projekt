#include <iostream>
#include <string>

#include "Support/support.h"
#include "Maze/maze.h"
#include <ctime>

int main() {
    srand(time(NULL));
    std::cout
            << "To generate a labyrinth, please enter its width x height (example 7 x 3).\nThe default is 5 x 5.\nInput : ";
    std::string input;
    //std::getline(std::cin, input);


    Maze maze(defaultWidth, defaultHeight);
    maze.display();

    std::cout << "\n\n";
    system("PAUSE");

    return 0;

}
