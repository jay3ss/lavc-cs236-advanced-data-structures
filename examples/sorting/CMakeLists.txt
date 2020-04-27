cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-std=c++11")
project("Examples - Sorting")

add_library(sort sort.h)
set_target_properties(
    sort
    PROPERTIES LINKER_LANGUAGE CXX
)

add_executable(main main.cpp)
target_link_libraries(main sort)
