//
// Created by Dodo on 2024-03-27.
//

#include <stack>
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
 */
void Maze::init_grid() {
    this->grid.clear();
    for (int y = 0; y < this->height; ++y) {
        std::vector<Node> row;
        for (int x = 0; x < this->width; ++x) {
            row.push_back(Node(x, y));
        }
        this->grid.push_back(row);
    }
}


/**
 * Generate the Maze using DFS
 */
/*
void Maze::generateMazeDFS() {
   // Make sure all the nodes are set to non-visited
   for (auto &row: this->grid) {
       for (auto &node: row) {
           node.visited = false;
       }
   }

   // Start DFS from the start point, this has been randomized already, it coheres with DFS
   std::stack<Node *> stack;
   Node *current = startingNode;
   current->visited = true;
   stack.push(current);

   while (!stack.empty()) {
       current = stack.top();
       auto neighbours = getUnvisitedNeighbours(current);

       if (!neighbours.empty()) {
           Node *next = chooseRandomNeighbour(neighbours);
           removeWall(current, next);

           next->visited = true;
           stack.push(next);
       } else {
           stack.pop();
       }
   }

}*/


/**
 * Print the maze
 */
void Maze::display() {
    if (startingNode == nullptr) {
        throw std::runtime_error("Maze is empty, nothing to display");
    }
    std::cout << "\n\n";
    for (auto &row: this->grid) {
        for (auto &node: row) {
            if (&node == startingNode) {
                std::cout << "S";
            } else if (&node == endNode) {
                std::cout << "E";
            } else if (node.isWall) {
                std::cout << "#"; // The walls are : "#"
            } else {
                std::cout << " "; // The paths are : " "
            }
        }
        std::cout << "\n";
    }
}

/**
 * Set the start and end of the maze
 */
void Maze::setPoints() {
    size_t startSide = rand() % 4; // Random side, 0 = top, 1 = right, 2 = bottom, 3 = left
    size_t endSide = rand() % 4; // Ensures the endSide to be different from the startSide
    while (endSide == startSide) {
        endSide = rand() % 4;
    }

    size_t startPos;
    size_t endPos;

    if (startSide % 2 == 0) {
        startPos = 1 + rand() % (this->width - 2);
    } else {
        startPos = 1 + rand() % (this->height - 2);
    }

    if (endSide % 2 == 0) {
        endPos = 1 + rand() % (this->width - 2);
    } else {
        endPos = 1 + rand() % (this->height - 2);
    }

    if (startSide == 0) {
        startingNode = &this->grid[0][startPos];
    } else if (startSide == 1) {
        startingNode = &this->grid[startPos][this->width - 1];
    } else if (startSide == 2) {
        startingNode = &this->grid[this->height - 1][startPos];
    } else if (startSide == 3) {
        startingNode = &this->grid[startPos][0];
    } else {
        throw std::runtime_error("Incorrect starting placement");
    }

    if (endSide == 0) {
        endNode = &this->grid[0][endPos];
    } else if (endSide == 1) {
        endNode = &this->grid[endPos][this->width - 1];
    } else if (endSide == 2) {
        endNode = &this->grid[this->height - 1][endPos];
    } else if (endSide == 3) {
        endNode = &this->grid[endPos][0];
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
    this->visited = false;
}

/**
 * Constructor for Node with specific coordinates
 * @param x x-coordinate
 * @param y y-coordinate
 */
Maze::Node::Node(int x, int y) {
    this->x = x;
    this->y = y;
    this->visited = false;
}
