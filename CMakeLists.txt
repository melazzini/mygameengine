cmake_minimum_required(VERSION 3.7..3.21 FATAL_ERROR)

project(mygameengine LANGUAGES CXX)

add_subdirectory(src)
add_subdirectory(test)

add_executable(app main.cpp)


