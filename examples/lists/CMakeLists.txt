cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-std=c++11")
project("Examples - Lists")

add_library(listadt ListInterface.h)
add_library(linkedlist LinkedList.h)
add_library(arraylist ArrayList.h)
add_library(node Node.h)

set_target_properties(
    listadt
    linkedlist
    arraylist
    node
    PROPERTIES LINKER_LANGUAGE CXX
)

target_link_libraries(linkedlist listadt node)
target_link_libraries(arraylist listadt)

add_executable(main main.cpp)
target_link_libraries(main linkedlist arraylist)

add_executable(linkedtests linkedtests.cpp)
target_link_libraries(linkedtests linkedlist)

add_executable(arraytests arraytests.cpp)
target_link_libraries(arraytests arraylist)
