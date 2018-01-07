cmake_minimum_required(VERSION 3.1.3)

project(Math3D VERSION 0.1 LANGUAGES CXX)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(include)

enable_testing()
add_subdirectory(bin)
add_subdirectory(src)
add_subdirectory(tst)

