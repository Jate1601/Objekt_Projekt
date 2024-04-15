//
// Created by Dodo on 2024-03-27.
//

#ifndef OBJEKT_PROJEKT_MAZE_H
#define OBJEKT_PROJEKT_MAZE_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


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

        std::vector<Node *> neighbours = {};
        int x, y;
    };

    size_t width, height;

    std::vector<std::vector<Node>> grid;

    Node *startingNode = nullptr;
    Node *endNode = nullptr;

    void init_grid();

    void setPoints();

    void generateMazeDFS();


    Node *randAdjacentNode(std::vector<Node *> &);

    std::vector<Node *> getAdjacentNodes(Node *current);

    void remove_wall(Node *from, Node *to);

    bool isConnected(Node *, Node *);
};

#endif //OBJEKT_PROJEKT_MAZE_H
