cmake_minimum_required(VERSION 3.6)
project(project1)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Board.h Board.cpp Board.h Player.cpp Player.h Grid.cpp Grid.h)
add_executable(project1 ${SOURCE_FILES})