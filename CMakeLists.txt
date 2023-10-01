cmake_minimum_required(VERSION 3.26)
project(Machine_learning_Connect4)

set(CMAKE_CXX_STANDARD 20)

add_executable(C4ML main/main.cpp
        Connect4/Connect4.cpp
        Connect4/Connect4.h
        Machine_Learning/DecisionTree.cpp
        Machine_Learning/DecisionTree.h
        File/FileMangement.cpp
        File/FileMangement.h
        Machine_Learning/Node.cpp
        Machine_Learning/Node.h
        Machine_Learning/ML_Agent.h
        Machine_Learning/ML_Agent.cpp
)
