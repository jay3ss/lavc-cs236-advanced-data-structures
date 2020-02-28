cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-std=c++11")
project(assignment01)

add_library(${PROJECT_NAME}_tictactoe TicTacToe.cpp)

add_executable(main main.cpp)
target_link_libraries(main ${PROJECT_NAME}_tictactoe)

add_executable(tests test.cpp)
target_link_libraries(tests ${PROJECT_NAME}_tictactoe)
