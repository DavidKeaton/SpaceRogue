cmake_minimum_required(VERSION 3.14)
project(spacerogue)
set(CMAKE_CXX_STANDARD 14)

add_executable(spacerogue main.cpp Logger.cpp Logger.h Video.cpp Video.h Input.cpp Input.h)