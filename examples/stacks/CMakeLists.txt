cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-std=c++11")
project("Examples - Stacks")

add_library(stackinterface StackInterface.h)
add_library(arraystack ArrayStack.h)
add_library(linkedstack LinkedStack.h)
add_library(node Node.h)

set_target_properties(
    stackinterface
    arraystack
    linkedstack
    node
    PROPERTIES LINKER_LANGUAGE CXX
)

target_link_libraries(arraystack stackinterface)
target_link_libraries(linkedstack stackinterface node)

# add_executable(main main.cpp)
# target_link_libraries(main )
