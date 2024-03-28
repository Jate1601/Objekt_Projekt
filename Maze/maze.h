//
// Created by Dodo on 2024-03-27.
//

#ifndef OBJEKT_PROJEKT_MAZE_H
#define OBJEKT_PROJEKT_MAZE_H

//#include<iostream>
#include <vector>

class Maze {
public:
    Maze();

    Maze(size_t width, size_t height);

    //Maze(const std::string fileName);

    ~Maze();

    void print();

    void solve();

    void generate();

    void set_dimension(size_t width, size_t height);

    const size_t get_height() {
        return this->height;
    }

    const size_t get_width() {
        return this->width;
    }

private:
    size_t width, height;

    struct Node {
        bool visited = false;
        bool topWall = true;
        bool bottomWall = true;
        bool leftWall = true;
        bool rightWall = true;
        int x, y;

        Node(int x, int y) : x(x), y(y) {};
    };

    std::vector<std::vector<Node>> grid;
    Node *start;
    Node *end;

    void initializeGrid();
};

#endif //OBJEKT_PROJEKT_MAZE_H
