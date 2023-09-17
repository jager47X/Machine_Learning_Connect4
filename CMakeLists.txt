cmake_minimum_required(VERSION 3.26)
project(Machine_learning_Connect4)

set(CMAKE_CXX_STANDARD 20)

add_executable(C4ML main.cpp
        Connect4.cpp
        Connect4.h
        DecisionTree.cpp
        DecisionTree.h
        FileMangement.cpp
        FileMangement.h
        Node.cpp
        Node.h
)
