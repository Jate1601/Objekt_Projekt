//
// Created by Dodo on 2024-03-27->
//

#ifndef OBJEKT_PROJEKT_FINDWIDTHANDHEIGHT_H
#define OBJEKT_PROJEKT_FINDWIDTHANDHEIGHT_H

#include "support.h"
#include <iostream>
#include <string>
#include "../Maze/maze.h"

/**
 * Find the defaultWidth and defaultHeight of the input-> Seperated by an x or a blank space->
 * @param input string entered by the user
 */
void findWidthAndHeight(std::string *input, Maze *maze);

#endif //OBJEKT_PROJEKT_FINDWIDTHANDHEIGHT_H
