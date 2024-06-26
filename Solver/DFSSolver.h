#ifndef OBJEKT_PROJEKT_DFSSOLVER_H
#define OBJEKT_PROJEKT_DFSSOLVER_H

#include "../Maze/maze.h"
#include <iostream>

class DFSSolver {
public:
    DFSSolver(Maze *maze);

    void solveDFS();

    void displaySolution() const;

private:
    Maze *maze;

    bool dfs(Maze::Node *node);

    std::vector<Maze::Node *> solutionPath;
};

#endif //OBJEKT_PROJEKT_DFSSOLVER_H
