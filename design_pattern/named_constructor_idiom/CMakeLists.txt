cmake_minimum_required(VERSION 3.10)

project(named_constructor_idiom)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# include dizinini dahil et
include_directories(${CMAKE_SOURCE_DIR}/include)

# factory adında çalıştırılabilir dosya oluştur
add_executable(factory src/main.cpp)
