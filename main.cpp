/**
 * Written by Jazzley Termond, Jate1601.
 * Written for course : DT019G/DT026G.
 * Aiming for grade : C
 */
 
#include <iostream>
#include <string>
#include "Maze/maze.h"
#include "Solver/DFSSolver.h"
#include "Support/findWidthAndHeight.h"
#include <ctime>

/**
 * The core of the program.
 * This project creates a maze using Deep First Search and also solves the generated
 * maze using DFS.
 *
 */
int main() {
    bool cont = true;
    srand(time(NULL));
    Maze *maze = nullptr;
    while (cont) {
        std::cin.clear();
        std::cout << "Please pick an option: "
                     "\n1.Generate and display a maze."
                     "\n2.Solve a generated maze."
                     "\n3.Clear the screen"
                     "\n4.Exit"
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
                        << "\nTo generate a new labyrinth, please enter its width x height (example 7 x 3).\nThe default is 5 x 5. A maze needs to have a width and/or height bigger than 1.\nInput : ";
                std::getline(std::cin, input);
                while (input.contains('-')) {
                    std::cout << "\nIncorrect input of negative number(s)!\nPlease enter a new width x height. : ";
                    std::getline(std::cin, input);
                }
                inputVec = findWidthAndHeight(&input);
                delete maze;
                if (inputVec[0] == defaultWidth && inputVec[1] == defaultHeight) maze = new Maze();
                else maze = new Maze(inputVec[0], inputVec[1]);

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
                system("cls");
                break;
            case 4:
                cont = false;
                break;
            default:
                break;
        }
        std::cout << "\n\n";
    }
    return 0;
}
