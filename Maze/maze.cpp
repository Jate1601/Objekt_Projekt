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
    this->height = defaultHeight;
    this->width = defaultWidth;

    this->init_grid();
}

/**
 * Constructor for the Maze with the passed width and height, //adds 2 to the size for the walls//
 * @param width width of the Maze
 * @param height height of the Maze
 */
Maze::Maze(size_t width, size_t height) {
    //this->height = height + 2;
    this->height = height;

    //this->width = width + 2;
    this->width = width;

    this->init_grid();
    this->setPoints();
    this->generateMazeDFS();
}

/**
 * Initializes the grid.
 */
void Maze::init_grid() {
    this->grid.clear();
    for (int y = 0; y < this->height; ++y) {
        std::vector<Node> row;
        for (int x = 0; x < this->width; ++x) {
            Node node(x, y);
            row.push_back(node);
        }
        this->grid.push_back(row);
    }
}


/**
 * Generate the Maze using DFS
 */
void Maze::generateMazeDFS() {
    std::stack<Node *> stack;
    startingNode->visited = true;
    stack.push(startingNode);

    while (!stack.empty()) {
        Node *current = stack.top();
        current->visited = true;
        auto neighbors = getAdjacentNodes(current);
        std::vector<Node *> unvisitedNeighbors;

        // Filter unvisited neighbors
        for (Node *neighbor: neighbors) {
            if (!neighbor->visited) {
                unvisitedNeighbors.push_back(neighbor);
            }
        }

        if (!unvisitedNeighbors.empty()) {
            Node *next = randAdjacentNode(unvisitedNeighbors); // This should use the filtered unvisited list
            remove_wall(current, next);
            next->visited = true;
            stack.push(next);
        } else {
            stack.pop();
        }
    }
}


/**
 * Get all the adjacent nodes coordinate wise
 * @param current current node
 * @return list of adjacent nodes
 */
std::vector<Maze::Node *> Maze::getAdjacentNodes(Maze::Node *current) {
    std::vector<Node *> adjacent = {};
    int x = current->x;
    int y = current->y;

    // Check left
    if (x > 0) adjacent.push_back(&this->grid[y][x - 1]);
    // Check Right
    if (x < this->width - 1) adjacent.push_back(&this->grid[y][x + 1]);
    // Check up
    if (y > 0) adjacent.push_back(&this->grid[y - 1][x]);
    // Check down
    if (y < height - 1) adjacent.push_back(&this->grid[y + 1][x]);

    return adjacent;
}

/**
 * Get a random adjacent node
 * @param nodes list of neighbours
 * @return random neighbour
 */
Maze::Node *Maze::randAdjacentNode(std::vector<Maze::Node *> &nodes) {
    if (nodes.empty()) {
        throw std::runtime_error("No available neighbours to choose from.");
    }
    int index = rand() % nodes.size();
    return nodes[index];
}

/**
 * Print the maze
 */
void Maze::display() {
    std::cout << "\n+"; // Start the top border
    for (int x = 0; x < width; x++) {
        std::cout << "--+"; // Top border of each cell
    }
    std::cout << "\n";

    for (int y = 0; y < height; y++) {
        std::cout << "|"; // Start the left border of the maze
        for (int x = 0; x < width; x++) {
            // Display start (S) or end (E) based on coordinates
            if (startingNode->x == x && startingNode->y == y) {
                std::cout << " S";
            } else if (endNode->x == x && endNode->y == y) {
                std::cout << " E";
            } else {
                std::cout << "  ";
            }

            // Display the right wall if there is no connection to the right neighbor
            if (x < width - 1 && !isConnected(&grid[y][x], &grid[y][x + 1])) {
                std::cout << "|";
            } else {
                std::cout << " ";
            }
        }
        std::cout << "|\n"; // Right border of the maze

        // Display the bottom walls if there is no connection to the bottom neighbor
        std::cout << "+"; // Start the line for bottom walls
        for (int x = 0; x < width; x++) {
            // Ensure bottom row always has a full wall, regardless of connections
            if (y < height - 1) {
                if (!isConnected(&grid[y][x], &grid[y + 1][x])) {
                    std::cout << "--+";
                } else {
                    std::cout << "  +";
                }
            } else {
                std::cout << "--+"; // Always print full walls for the bottom-most row
            }
        }
        std::cout << "\n";
    }
}

/**
 * Check of the two nodes are neighbours.
 * @param n1 first node
 * @param n2 second node
 * @return true if neighbours, false if not
 */
bool Maze::isConnected(Node *n1, Node *n2) {
    return std::find(n1->neighbours.begin(), n1->neighbours.end(), n2) != n1->neighbours.end();
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

    size_t startPos = rand() % ((startSide % 2 == 0) ? this->width : this->height);
    size_t endPos = rand() % ((endSide % 2 == 0) ? this->width : this->height);

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
 * Remove the wall between two nodes
 * @param from the original node
 * @param to its neighbour
 */
void Maze::remove_wall(Maze::Node *from, Maze::Node *to) {
    from->neighbours.push_back(to);
    to->neighbours.push_back(from);
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
