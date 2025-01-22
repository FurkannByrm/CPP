cmake_minimum_required(VERSION 3.10)

project(lidar)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(Boost REQUIRED COMPONENTS system)
add_executable(rp_lidar src/rp_lidar.cpp)
target_link_libraries(rp_lidar Boost::system pthread)
include_directories(${CMAKE_SOURCE_DIR}/include)
