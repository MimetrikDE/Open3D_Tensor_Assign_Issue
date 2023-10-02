cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

project(Open3D_Test LANGUAGES CUDA CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Open3D REQUIRED)

add_executable(Open3D_Test ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)

include_directories(Open3D_Test ${Open3D_INCLUDE_DIRS})
target_link_libraries(Open3D_Test PUBLIC Open3D::Open3D)


