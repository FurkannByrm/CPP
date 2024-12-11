cmake_minimum_required(VERSION 3.10)

# Proje ismi
project(memory_allocation)

# C++ standardını belirle
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# include dizinini belirt, buraya hpp dosyalarını ekleyeceksin
include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(shared_ptr src/shared_ptr.cpp)
add_executable(unique_ptr src/unique_ptr.cpp)

add_executable(new src/new.cpp)
