cmake_minimum_required(VERSION 3.10)

project(rp_lidar)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# RP-Lidar SDK yolu
set(RPLIDAR_SDK_PATH "/home/cengo/rplidar_sdk")

# Include dizinlerini ekle
include_directories(${RPLIDAR_SDK_PATH}/sdk/include)
include_directories(${RPLIDAR_SDK_PATH}/sdk/src)
include_directories(${RPLIDAR_SDK_PATH}/sdk/src/hal)
include_directories(${RPLIDAR_SDK_PATH}/sdk/src/arch/linux)

# Kütüphane dizinini ekle
link_directories(${RPLIDAR_SDK_PATH})

# Uygulama için kaynak dosyaları belirle
add_executable(rp_lidar src/main.cpp)

target_link_libraries(rp_lidar
    ${RPLIDAR_SDK_PATH}/output/Linux/Release/libsl_lidar_sdk.a
    pthread  # Eğer threading gerekiyorsa
)
