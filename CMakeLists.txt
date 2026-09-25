cmake_minimum_required(VERSION 4.3)
project(cli2048)

set(CMAKE_CXX_STANDARD 20)

add_executable(cli2048 main.cpp
        Map.cpp)
