cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-std=c++11")
project("Examples - Queues")

add_library(queueinterface QueueInterface.h)
add_library(fixedqueue FixedQueue.h)
add_library(floatingqueue FloatingQueue.h)
add_library(linkedqueue LinkedQueue.h)
add_library(node Node.h)

set_target_properties(
    queueinterface
    fixedqueue
    floatingqueue
    linkedqueue
    node
    PROPERTIES LINKER_LANGUAGE CXX
)

target_link_libraries(fixedqueue queueinterface)
target_link_libraries(floatingqueue queueinterface)
target_link_libraries(linkedqueue queueinterface node)

# add_executable(main main.cpp)
# target_link_libraries(main )

# Tests for FixedQueue class
add_executable(fixedqueuetests fixedqueuetests.cpp)
target_link_libraries(fixedqueuetests fixedqueue)

# Tests for FloatingQueue class
add_executable(floatingqueuetests floatingqueuetests.cpp)
target_link_libraries(floatingqueuetests floatingqueue)

# Tests for LinkedQueue class
add_executable(linkedqueuetests linkedqueuetests.cpp)
target_link_libraries(linkedqueuetests linkedqueue)

