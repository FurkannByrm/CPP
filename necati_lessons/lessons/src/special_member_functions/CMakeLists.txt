cmake_minimum_required(VERSION 3.10)

# Proje ismi
project(special_member_functions)

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


add_executable(copy_ctor src/copy_ctor.cpp)
add_executable(default_ctor src/default_ctor.cpp)

# Eğer ileride kütüphaneler linklemen gerekirse:
# target_link_libraries(10_14 <kütüphane_ismi>)
