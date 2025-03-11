cmake_minimum_required(VERSION 3.10)

# Proje ismi
project(searching_algorithms)

# C++ standardını belirle
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# include dizinini belirt, buraya hpp dosyalarını ekleyeceksin
include_directories(${CMAKE_SOURCE_DIR}/include/${CMAKE_SOURCE_DIR})


# İkinci executable (örneğin, main içeren other_main.cpp)
add_executable(linear_search
    src/linear_search.cpp
)
