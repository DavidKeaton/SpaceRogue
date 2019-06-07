cmake_minimum_required(VERSION 3.14)
project(spacerogue)
set(CMAKE_CXX_STANDARD 14)

add_executable(spacerogue src/main.cpp src/Logger.cpp src/Logger.h src/Video.cpp src/Video.h src/Input.cpp src/Input.h)