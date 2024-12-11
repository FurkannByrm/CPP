cmake_minimum_required(VERSION 3.10)

# Proje ismi
project(static_member_functions)

# C++ standardını belirle
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# include dizinini belirt, buraya hpp dosyalarını ekleyeceksin
include_directories(${CMAKE_SOURCE_DIR}/include)

# Kaynak dosyaları listele
#set(SOURCES
#    src/main.cpp
#    src/special_member_func.cpp
#)


add_executable(static src/static.cpp)
