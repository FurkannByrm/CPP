cmake_minimum_required(VERSION 3.10)

# Set the project name
project(MultithreadingExample VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
add_executable(6 src/6_raceCondition_01.cpp)
add_executable(7 src/7_raceCondition_02.cpp)
add_executable(8 src/8_raceCondition_03.cpp)
add_executable(9 src/9_conditionVariable_04.cpp)