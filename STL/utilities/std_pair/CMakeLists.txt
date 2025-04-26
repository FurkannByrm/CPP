cmake_minimum_required(VERSION 3.10)

# Project name
project(VectorPairExample LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# Add executable
add_executable(vector_pair src/vector_pair.cpp)
add_executable(queue_pair src/queue_pair.cpp)

# Include directories (if needed)
# target_include_directories(vector_pair PRIVATE include)

# Link libraries (if needed)
# target_link_libraries(vector_pair PRIVATE some_library)