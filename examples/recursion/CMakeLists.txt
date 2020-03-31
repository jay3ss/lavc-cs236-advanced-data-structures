cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-std=c++11")
project("Examples - Recursion")

add_library(functions functions.h)
set_target_properties(
    functions
    PROPERTIES LINKER_LANGUAGE CXX
)

add_executable(main main.cpp)
target_link_libraries(main functions)
