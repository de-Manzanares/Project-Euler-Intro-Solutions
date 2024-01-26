cmake_minimum_required(VERSION 3.27)
project(ProjectEulerSolutions)

set(CMAKE_CXX_STANDARD 17)

include_directories(src)

add_executable(ProjectEulerSolutions main.cpp
        src/Solution_1.cpp)
