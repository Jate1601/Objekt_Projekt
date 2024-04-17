/**
 * Written by Jazzley Termond, Jate1601.
 * Written for course : DT019G/DT026G.
 * Aiming for grade : C
 */

#include "DFSSolver.h"

/**
 * Constructor that initializes the solves with a maze
 * @param maze pointer to the maze that is being solved
 */
DFSSolver::DFSSolver(Maze *maze) : maze(maze) {}

/**
 * The DFS check to solve a maze. This calls the DFS method
 */
void DFSSolver::solveDFS() {
    if (dfs(maze->getStartingNode())) {
        std::cout << "Maze solved successfully. It took: " << this->solutionPath.size() - 1 << " steps\n";
        displaySolution();
    } else std::cout << "No solution found.\n";
}

/**
 * Recursive method to perform DFS from a given node
 * @param node current node
 * @return true of the maze is solvable, otherwise return false
 */
bool DFSSolver::dfs(Maze::Node *node) {
    if (node == nullptr || node->visited) return false;
    node->visited = true;
    this->solutionPath.push_back(node);
    if (node == maze->getEndNode()) return true;

    for (Maze::Node *neighbour: node->neighbours) {
        if (!neighbour->visited && dfs(neighbour)) return true;
    }

    this->solutionPath.pop_back();
    return false;
}

/**
 * Display the solution path to solve the maze
 */
void DFSSolver::displaySolution() const {
    for (const auto &node: solutionPath) {
        std::cout << "(" << node->x << ", " << node->y << ") ";
    }
    std::cout << "\n\n";
}