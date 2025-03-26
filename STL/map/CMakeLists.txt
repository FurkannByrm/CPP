cmake_minimum_required(VERSION 3.10)

# Set the project name
project(student)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable

include_directories(include)

set(SOURCES
    src/interpreter.cpp
    src/main.cpp
)

add_executable(MapExample ${SOURCES})