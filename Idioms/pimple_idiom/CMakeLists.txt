cmake_minimum_required(VERSION 3.10)

project(PIMPLE)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# add_executable(pimple src/main.cpp)
add_executable(pimple1 src/car.cpp)

include_directories(${CMAKE_SOURCE_DIR}/include)
