cmake_minimum_required(VERSION 3.10)

# Proje ismi
project(enum_class)

# C++ standardını belirle
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# include dizinini belirt, buraya hpp dosyalarını ekleyeceksin
include_directories(${CMAKE_SOURCE_DIR}/include)


add_executable(enum src/enum_class.cpp)