cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-std=c++11")
project(assignment05)

add_library(bstree BSTree.cpp)

add_executable(main main.cpp)
target_link_libraries(main bstree)

add_executable(tests tests.cpp)
target_link_libraries(tests bstree)
