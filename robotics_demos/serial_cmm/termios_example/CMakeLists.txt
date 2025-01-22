cmake_minimum_required(VERSION 3.10)

project(termios)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)



# Çalıştırılabilir dosya oluştur (10_14 adında)
add_executable(serial src/serial_posix.cpp)
include_directories(${CMAKE_SOURCE_DIR}/include)
