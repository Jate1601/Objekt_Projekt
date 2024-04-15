//
// Created by Dodo on 2024-04-15.
//

#include "DFSSolver.h"

DFSSolver::DFSSolver(Maze *maze) : maze(maze) {}

void DFSSolver::solveDFS() {
    if (dfs(maze->getStartingNode())) {
        std::cout << "Maze solved successfully. It took: " << this->solutionPath.size() - 1 << " steps\n";
        displaySolution();
    } else std::cout << "No solution found.\n";
}

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

void DFSSolver::displaySolution() const {
    for (const auto &node: solutionPath) {
        std::cout << "(" << node->x << ", " << node->y << ") ";
    }
    std::cout << std::endl;
}