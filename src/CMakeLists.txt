add_library(mygameengine ImagePrimitiveSdl.cpp utils.cpp Window.cpp WindowPrimitiveSdl.cpp)

target_include_directories(mygameengine PUBLIC ${CMAKE_SOURCE_DIR}/include)

set_target_properties(mygameengine PROPERTIES
                                    CXX_STANDARD 20
                                    CXX_STANDARD_REQUIRED ON)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/lib/modules") 

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

target_include_directories(mygameengine PRIVATE ${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})

target_link_libraries(mygameengine PRIVATE ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARY})