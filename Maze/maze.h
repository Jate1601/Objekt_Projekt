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

    void setPoints();

private:
    struct Node {
        Node();

        Node(int x, int y);

        bool start = false;
        bool end = false;

        bool isWall = true;
        int x;
        int y;
        std::vector<int> neighbours;
    };

    size_t width;
    size_t height;

    std::vector<std::vector<Node>> grid;

    void init_grid();
};

#endif //OBJEKT_PROJEKT_MAZE_H
