cmake_minimum_required(VERSION 3.10)

# Project name
project(unique_ptr_example)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(include)

# Add executable
add_executable(factory_exemple src/factory.cpp)

# Target include directories
target_include_directories(unique_ptr_example PRIVATE include)