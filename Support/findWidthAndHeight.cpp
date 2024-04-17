/**
 * Written by Jazzley Termond, Jate1601.
 * Written for course : DT019G/DT026G.
 * Aiming for grade : C
 */

#include "findWidthAndHeight.h"

/**
 * Find the width and height of the input. Seperated by an x or a blank space
 * @param input string entered by the user
 */
std::vector<size_t> findWidthAndHeight(std::string *input) {
    size_t xPos = input->find('x');
    if (xPos == std::string::npos) {
        xPos = input->find(' ');
        if (xPos == std::string::npos) {
            //std::cout << "\nIncorrect input! Using default settings->\n";
            return std::vector<size_t>{0, 0};

        }
    }
    // Extract the width before the x and the height after the x
    std::string widthStr = input->substr(0, xPos);
    std::string heightStr = input->substr(xPos + 1);

    // Convert and set the width and height
    size_t width = 0;
    size_t height = 0;
    try {
        width = std::stoi(widthStr);
        height = std::stoi(heightStr);
    } catch (std::invalid_argument const &ex) {
        width = 0;
        height = 0;
    }

    return std::vector<size_t>{width, height};
}
