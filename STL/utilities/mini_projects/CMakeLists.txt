cmake_minimum_required(VERSION 3.10)

# Project name
project(MiniProjects)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add include directory
include_directories(include)

# Add the executable
file(GLOB SOURCES "src/*.cpp")
add_executable(logAnalyzer ${SOURCES})

# Link include directory for .hpp files
target_include_directories(logAnalyzer PRIVATE include)