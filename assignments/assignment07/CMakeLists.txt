cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-std=c++11")
project(assignment07)

add_library(heap Heap.h)
set_target_properties(heap PROPERTIES LINKER_LANGUAGE CXX)

add_executable(main main.cpp)
target_link_libraries(main heap)

add_executable(tests tests.cpp)
target_link_libraries(tests heap)
