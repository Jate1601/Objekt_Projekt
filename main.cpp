#include <iostream>
#include <string>

#include "Support/support.h"
#include "Maze/maze.h"
#include "Solver/DFSSolver.h"
#include <ctime>

int main() {
    bool cont = true;
    srand(time(NULL));
    Maze *maze = nullptr;
    while (cont) {
        std::cin.clear();
        std::cout << "Please pick an option: "
                     "\n1.Generate and display a maze."
                     "\n2.Solve a generated maze."
                     "\n3.Exit"
                     "\nYour choice : ";
        int choice;
        std::cin >> choice;
        std::cin.clear();
        std::cin.ignore(10000, '\n');

        std::string input;
        std::vector<size_t> inputVec = {};

        switch (choice) {
            case 1:
                std::cout
                        << "To generate a new labyrinth, please enter its width x height (example 7 x 3).\nThe default is 5 x 5.\nInput : ";
                std::getline(std::cin, input);
                if (input.contains('-')) {
                    std::cout << "\nIncorrect input of negative number(s)!\n";
                    break;
                }
                inputVec = findWidthAndHeight(&input);
                delete maze;
                maze = new Maze(inputVec[0], inputVec[1]);
                maze->display();
                break;
            case 2:
                if (maze == nullptr) {
                    std::cout << "\nNo maze has been generated. Please generate a maze first.\n";
                } else {
                    DFSSolver solver(maze);
                    solver.solveDFS();
                }
                break;
            case 3:
                cont = false;
                break;
            default:
                break;
        }

        std::cout << "\n\n";
    }
    system("PAUSE");

    return 0;
}
