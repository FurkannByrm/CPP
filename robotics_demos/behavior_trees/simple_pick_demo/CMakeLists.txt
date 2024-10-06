cmake_minimum_required(VERSION 3.10)
project(SimplePickDemo)

# BehaviorTree.CPP kütüphanesinin kurulu olduğu dizini belirtin
set(BEHAVIOR_TREE_CPP_DIR "/usr/local")  # Kurulum dizini

# CMake'in BehaviorTree.CPP'yi bulabilmesi için CMAKE_PREFIX_PATH'e ekleyin
list(APPEND CMAKE_PREFIX_PATH "${BEHAVIOR_TREE_CPP_DIR}/install")

# BehaviorTree.CPP kütüphanesini bulun
#find_package(behaviortree_cpp_v3 REQUIRED)

# Uygulama kaynak dosyaları
set(SOURCES
    src/bt_demo.cpp  # Ana kaynak dosyanız
)

# Uygulama oluşturma
add_executable(SimplePickDemo ${SOURCES})

# BehaviorTree.CPP kütüphanesini bağlayın
target_link_libraries(SimplePickDemo PRIVATE behaviortree_cpp_v3)

# Include dizinlerini ekleyin
target_include_directories(SimplePickDemo PRIVATE
    ${BEHAVIOR_TREE_CPP_DIR}/include  # BehaviorTree.CPP başlık dosyaları
    ${CMAKE_CURRENT_SOURCE_DIR}/include  # Projenizin başlık dosyaları
)
