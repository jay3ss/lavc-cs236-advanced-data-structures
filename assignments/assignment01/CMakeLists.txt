cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-std=c++11")
project(assignment01)

add_library(${PROJECT_NAME}_tictactoe TicTacToe.cpp)

add_executable(tictactoemain main.cpp)
target_link_libraries(tictactoemain ${PROJECT_NAME}_tictactoe)

add_executable(tictactoetest test.cpp)
target_link_libraries(tictactoetest ${PROJECT_NAME}_tictactoe)
