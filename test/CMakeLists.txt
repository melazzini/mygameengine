enable_testing()

add_executable(cpp_test maintest.cpp ImageTest.cpp ImageLoaderTest.cpp RendererTest.cpp)

set_target_properties(cpp_test PROPERTIES 
                        CXX_STANDARD 20
                        CXX_STANDARD_REQUIRED ON
                        )

add_test(mytest cpp_test)

target_include_directories(cpp_test PRIVATE "${CMAKE_SOURCE_DIR}/include")

target_link_libraries(cpp_test gtest gmock gtest_main pthread)