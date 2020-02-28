cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-std=c++11")
project(assignment02)

# add_library(${PROJECT_NAME}_)

add_executable(main main.cpp)
# target_link_libraries(main ${PROJECT_NAME}_)

add_executable(tests test.cpp)
# target_link_libraries(tests ${PROJECT_NAME}_)
