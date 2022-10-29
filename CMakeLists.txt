cmake_minimum_required(VERSION 3.11)
project(DFA)

include_directories(./src )

set(CMAKE_CXX_STANDARD 11)
set(SOURCE_FILES src/main.cpp src/DFA.cpp src/Node.cpp src/DFA.h src/Arc.h src/Node.h)

add_executable(DFA src/main.cpp src/DFA.cpp src/Node.cpp src/helpers.cpp src/helpers.h)
