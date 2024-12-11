cmake_minimum_required(VERSION 3.10)

# Proje ismi
project(linked_list)

# C++ standardını belirle
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# include dizinini belirt, buraya hpp dosyalarını ekleyeceksin
include_directories(${CMAKE_SOURCE_DIR}/include)

# İlk executable (rearrange_naive.cpp ile)
add_executable(linkedList
    src/linked_list.cpp
)
add_executable(adding_to_list
    src/adding_to_list.cpp
)
add_executable(sorted_insert
    src/sorted_insert.cpp
)