//
// Created by Dodo on 2024-03-27.
//

#ifndef OBJEKT_PROJEKT_FINDWIDTHANDHEIGHT_H
#define OBJEKT_PROJEKT_FINDWIDTHANDHEIGHT_H

#include "support.h"
#include <string>

/**
 * Find the width and height of the input. Seperated by an x or a blank space.
 * @param input string entered by the user
 */
void findWidthAndHeight(std::string &input) {
    size_t xPos = input.find('x');
    if (xPos == std::string::npos) {
        xPos = input.find(' ');
        if (xPos == std::string::npos) {
            std::cerr << "\nIncorrect input! Using default settings.\n";
            return;
        }
    }
// Extract the width before the x and the height after the x
    std::string widthStr = input.substr(0, xPos);
    std::string heightStr = input.substr(xPos + 1);

// Convert and set the width and height
    width = std::stoi(widthStr);
    height = std::stoi(heightStr);
}

#endif //OBJEKT_PROJEKT_FINDWIDTHANDHEIGHT_H
