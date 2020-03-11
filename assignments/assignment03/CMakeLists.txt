cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-std=c++11")
project(assignment03)

add_library(${PROJECT_NAME}_stack ADTStackLList.h)
set_target_properties(${PROJECT_NAME}_stack PROPERTIES LINKER_LANGUAGE CXX)

add_executable(main ADTStackLList.cpp)
target_link_libraries(main ${PROJECT_NAME}_stack)

add_executable(tests tests.cpp)
target_link_libraries(tests ${PROJECT_NAME}_stack)
