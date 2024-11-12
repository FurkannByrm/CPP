cmake_minimum_required(VERSION 3.10)

project(SerialPortRead)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(serial_read src/serial_read.cpp)
add_executable(serial_write src/serial_write.cpp)

target_link_libraries(serial_read PRIVATE pthread)
