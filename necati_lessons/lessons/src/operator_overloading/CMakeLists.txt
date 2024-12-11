cmake_minimum_required(VERSION 3.10)

# Proje ismi
project(operator_overloading)

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


set(SOURCES
    src/main.cpp
    src/mint.cpp
)


add_executable(mint ${SOURCES})


# Eğer ileride kütüphaneler linklemen gerekirse:
# target_link_libraries(10_14 <kütüphane_ismi>)
