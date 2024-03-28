//
// Created by Dodo on 2024-03-27.
//

#include "maze.h"
#include "../Support/support.h"

/**
 * Default constructor for the Maze. Sets the size to 5x5 (defined in appConfig)
 */
Maze::Maze() {
    //set_dimension(defaultWidth, defaultHeight);
    this->width = defaultWidth;
    this->height = defaultHeight;
    this->end = nullptr;
    this->start = nullptr;
}

/**
 * Constructor for the Maze with the passed width and height
 * @param width width of the Maze
 * @param height height of the Maze
 */
Maze::Maze(size_t width, size_t height) {
    set_dimension(width, height);
}

/**
 * Deconstructor of the Maze
 */
Maze::~Maze() {

}


void Maze::set_dimension(size_t width, size_t height) {
    this->width = width;
    this->height = height;
}

void Maze::print() {

}

void Maze::solve() {

}

void Maze::generate() {

}

void Maze::initializeGrid() {

}




