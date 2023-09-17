cmake_minimum_required(VERSION 3.26)
project(C4ML)

set(CMAKE_CXX_STANDARD 20)

add_executable(C4ML main.cpp
        Connect4.cpp
        Connect4.h)
