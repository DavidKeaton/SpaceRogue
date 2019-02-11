cmake_minimum_required(VERSION 3.13)
project(spacerogue)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(src)

add_executable(spacerogue
        src/SpaceRogue.cpp src/SpaceRogue.h
        src/main.cpp)
