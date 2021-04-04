cmake_minimum_required(VERSION 3.17)
project(src)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_EXE main.cpp)
set(TASK1_EXE task1.cpp)
set(TASK2_EXE task2.cpp)
set(TASK3_EXE task3.cpp)
set(SQUARE_EXE Square.cpp)

add_library(task1 STATIC ${TASK1_EXE})
add_library(task2 STATIC ${TASK2_EXE})
add_library(task3 STATIC ${TASK3_EXE})
add_library(Square STATIC ${SQUARE_EXE})

add_executable(main ${SOURCE_EXE})

target_link_libraries(main task1)
target_link_libraries(main task2)
target_link_libraries(main task3)
target_link_libraries(main Square)
