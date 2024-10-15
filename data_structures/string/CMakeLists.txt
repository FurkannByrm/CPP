cmake_minimum_required(VERSION 3.10)

# Proje ismi
project(string)

# C++ standardını belirle
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# include dizinini belirt, buraya hpp dosyalarını ekleyeceksin
include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(concatenation
    src/str_concatenation.cpp
)

# Eğer ileride kütüphaneler linklemen gerekirse:
# target_link_libraries(rearrange_naive_executable <kütüphane_ismi>)
# target_link_libraries(other_main_executable <kütüphane_ismi>)
