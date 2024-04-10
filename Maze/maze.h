//
// Created by Dodo on 2024-03-27.
//

#ifndef OBJEKT_PROJEKT_MAZE_H
#define OBJEKT_PROJEKT_MAZE_H

#include <iostream>
#include <string>
#include <vector>

class Maze {
public:
    Maze();

    Maze(size_t width, size_t height);

    void display();

private:
    struct Node {
        Node();

        Node(int x, int y);

        bool visited;

        bool isWall = true;
        int x, y;
        std::vector<int> neighbours;
    };

    size_t width, height;

    std::vector<std::vector<Node>> grid;

    Node *startingNode = nullptr;
    Node *endNode = nullptr;

    void init_grid();

    void generateMazeDFS();

    void setPoints();


};

#endif //OBJEKT_PROJEKT_MAZE_H
