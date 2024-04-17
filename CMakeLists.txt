cmake_minimum_required(VERSION 3.27)
project(objekt_projekt)

set(CMAKE_CXX_STANDARD 23)

add_executable(objekt_projekt main.cpp
        Support/appConfig.h
        Support/findWidthAndHeight.h
        Maze/maze.h
        Maze/maze.cpp
        Support/findWidthAndHeight.cpp
        Solver/DFSSolver.cpp
        Solver/DFSSolver.h
)
