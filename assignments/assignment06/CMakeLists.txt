cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-std=c++11")
project(assignment06)

add_library(avltree AVLTree.h)
set_target_properties(avltree PROPERTIES LINKER_LANGUAGE CXX)

add_executable(main main.cpp)
target_link_libraries(main avltree)

add_executable(tests tests.cpp)
target_link_libraries(tests avltree)
