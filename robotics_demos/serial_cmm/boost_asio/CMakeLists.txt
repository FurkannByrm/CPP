cmake_minimum_required(VERSION 3.10)

project(SerialPortRead)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(Boost REQUIRED COMPONENTS system)
add_executable(write src/write.cpp)
add_executable(serial_port_open src/serial_port_open.cpp)
add_executable(read src/read.cpp)
add_executable(read_write src/read_write.cpp)

target_link_libraries(serial_port_open Boost::system pthread)
target_link_libraries(write Boost::system pthread)
target_link_libraries(read Boost::system pthread)
target_link_libraries(read_write Boost::system pthread)
include_directories(${CMAKE_SOURCE_DIR}/include)
