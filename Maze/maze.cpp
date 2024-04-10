//
// Created by Dodo on 2024-03-27.
//

#include "Maze.h"
#include "../Support/appConfig.h"

/**
 * Default constructor for the Maze. Sets the size to 5x5 (defined in appConfig)
 */
Maze::Maze() {
    //TODO add walls
    this->height = defaultHeight;
    this->width = defaultWidth;

    this->init_grid();
}

/**
 * Constructor for the Maze with the passed width and height, adds 2 to the size for the walls
 * @param width width of the Maze
 * @param height height of the Maze
 */
Maze::Maze(size_t width, size_t height) {
    this->height = height + 2;
    this->width = width + 2;

    this->init_grid();
    this->setPoints();
}

/**
 * Initializes the grid.
 * If user entered 5x5, grid is generated for 7x7 but the size for the actual maze remains 5x5
 */
void Maze::init_grid() {
    this->grid = std::vector<std::vector<Node>>(this->height, std::vector<Node>(width));
    //this->grid[0][1].start = true;
    //this->grid[6][5].end = true;
}

/**
 * Print the maze
 */
void Maze::display() {
    std::cout << "\n\n";
    for (int y = 0; y < this->height; ++y) {
        for (int x = 0; x < this->width; ++x) {
            if (grid[y][x].start) {
                std::cout << "S";
            } else if (grid[y][x].end) {
                std::cout << "E";
            } else if (grid[y][x].isWall) {
                std::cout << "#"; // The walls are : "#"
            } else {
                std::cout << " "; // The paths are : " "
            }
        }
        std::cout << "\n";
    }
    std::cout << "\n\n";
}

/**
 * Set the start and end of the maze
 */
void Maze::setPoints() {
    size_t height = this->height - 2; // Remove 3. 2 for the walls and 1 for the zero index
    size_t width = this->width - 2;

    size_t startSide = rand() % 4; // Random side, 0 = top, 1 = right, 2 = bottom, 3 = left

    size_t endSide = rand() % 4; // Ensures the endSide to be different from the startSide
    while (endSide == startSide) {
        endSide = rand() % 4;
    }


    size_t startPos;
    size_t endPos;

    if (startSide % 2 == 0) {
        startPos = 1 + rand() % width;
    } else {
        startPos = 1 + rand() % height;
    }

    if (endSide % 2 == 0) {
        endPos = 1 + rand() % width;
    } else {
        endPos = 1 + rand() % height;
    }

    if (startSide == 0) {
        this->grid[0][startPos].start = true;
    } else if (startSide == 1) {
        this->grid[startPos][this->width - 1].start = true;
    } else if (startSide == 2) {
        this->grid[this->height - 1][startPos].start = true;
    } else if (startSide == 3) {
        this->grid[startPos][0].start = true;
    } else {
        throw std::runtime_error("Incorrect starting placement");
    }

    if (endSide == 0) {
        this->grid[0][endPos].end = true;
    } else if (endSide == 1) {
        this->grid[endPos][this->width - 1].end = true;
    } else if (endSide == 2) {
        this->grid[this->height - 1][endPos].end = true;
    } else if (endSide == 3) {
        this->grid[endPos][0].end = true;
    } else {
        throw std::runtime_error("Incorrect ending placement");
    }

}

/**
 * Default constructor for Node
 */
Maze::Node::Node() {
    this->x = 0;
    this->y = 0;
}

/**
 * Constructor for Node with specific coordinates
 * @param x x-coordinate
 * @param y y-coordinate
 */
Maze::Node::Node(int x, int y) {
    this->x = x;
    this->y = y;
}
