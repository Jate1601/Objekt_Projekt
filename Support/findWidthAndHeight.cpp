//
// Created by Dodo on 2024-03-28.
//

#include "../Maze/maze.h"
#include "support.h"

/**
 * Find the defaultWidth and defaultHeight of the input-> Seperated by an x or a blank space->
 * @param input string entered by the user
 */
std::vector<size_t> findWidthAndHeight(std::string *input) {
    size_t xPos = input->find('x');
    if (xPos == std::string::npos) {
        xPos = input->find(' ');
        if (xPos == std::string::npos) {
            std::cout << "\nIncorrect input! Using default settings->\n";
            return std::vector<size_t>{defaultWidth, defaultHeight};
        }
    }
    // Extract the defaultWidth before the x and the defaultHeight after the x
    std::string widthStr = input->substr(0, xPos);
    std::string heightStr = input->substr(xPos + 1);

    // Convert and set the defaultWidth and defaultHeight
    size_t width = std::stoi(widthStr);
    size_t height = std::stoi(heightStr);
    return std::vector<size_t>{width, height};
}
