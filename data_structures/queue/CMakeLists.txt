cmake_minimum_required(VERSION 3.10)

# Proje ismi
project(queue)

# C++ standardını belirle
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# include dizinini belirt, buraya hpp dosyalarını ekleyeceksin
include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(concatenation
    src/queue.cpp
)
