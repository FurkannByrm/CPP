cmake_minimum_required(VERSION 3.10)

# Proje ismi
project(array)

# C++ standardını belirle
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# include dizinini belirt, buraya hpp dosyalarını ekleyeceksin
include_directories(${CMAKE_SOURCE_DIR}/include)

# İlk executable (rearrange_naive.cpp ile)
add_executable(rearrange_naive
    src/rearrange_naive.cpp
)

# İkinci executable (örneğin, main içeren other_main.cpp)
add_executable(sort_array
    src/sort_array.cpp
)

add_executable(product_array
    src/product_array_except_self.cpp
)

add_executable(reorder
    src/reorder_array.cpp
)

add_executable(minimum_sorted
    src/minimum_sorted_array.cpp
)

# Eğer ileride kütüphaneler linklemen gerekirse:
# target_link_libraries(rearrange_naive_executable <kütüphane_ismi>)
# target_link_libraries(other_main_executable <kütüphane_ismi>)
