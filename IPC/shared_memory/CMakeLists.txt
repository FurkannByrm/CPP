cmake_minimum_required(VERSION 3.10)

project(shared_memory)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(shared src/shared.cpp)
add_executable(access src/access.cpp)