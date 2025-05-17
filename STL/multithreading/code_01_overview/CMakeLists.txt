cmake_minimum_required(VERSION 3.10)

# Set the project name
project(MultithreadingOverview)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
add_executable(1 src/1_singleThread.cpp)
add_executable(2 src/2_multithreaded_01.cpp)
add_executable(3 src/3_multithreaded_02.cpp)
add_executable(4 src/4_multithreaded_03.cpp)
add_executable(5 src/5_multithreaded_04.cpp)