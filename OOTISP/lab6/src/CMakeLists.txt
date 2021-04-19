cmake_minimum_required(VERSION 3.19)
project(src)

set(CMAKE_CXX_STANDARD 14)

set(TASK1_EXE task1.cpp)
set(TASK2_EXE task2.cpp)
set(PERSON_EXE Person.cpp)
set(MAIN_EXE main.cpp)

add_library(Person STATIC ${PERSON_EXE})
add_library(task1 STATIC ${TASK1_EXE})
add_library(task2 STATIC ${TASK2_EXE})

add_executable(main ${MAIN_EXE})

target_link_libraries(task1 Person)
target_link_libraries(main task1)
target_link_libraries(main task2)
