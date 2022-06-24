cmake_minimum_required(VERSION 3.7..3.21 FATAL_ERROR)

project(mygameengine LANGUAGES CXX)

include_directories("${CMAKE_SOURCE_DIR}/lib/gsl/_deps/gsl-src/include")

add_subdirectory(src)
add_subdirectory(test)

add_executable(app main.cpp)

set_target_properties(app PROPERTIES
                            CXX_STANDARD 20
                            CXX_STANDARD_REQUIRED ON)

target_link_libraries(app mygameengine)


