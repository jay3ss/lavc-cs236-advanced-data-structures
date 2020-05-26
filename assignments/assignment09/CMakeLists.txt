cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-std=c++11")
project(assignment09)

add_library(graph Graph.h)
set_target_properties(graph PROPERTIES LINKER_LANGUAGE CXX)

add_executable(main main.cpp)
target_link_libraries(main graph)

add_executable(tests tests.cpp)
target_link_libraries(tests graph)
