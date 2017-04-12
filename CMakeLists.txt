cmake_minimum_required(VERSION 3.7)
project(lab07_01)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp node_t.h Set.h String.cpp String.h)
add_executable(lab07_01 ${SOURCE_FILES})