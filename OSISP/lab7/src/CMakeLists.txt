cmake_minimum_required(VERSION 3.19)
project(src C)

set(CMAKE_C_STANDARD 99)

find_package(Threads)
find_library(LIBRT rt)

add_executable(producer producer.c)
add_executable(consumer consumer.c)

target_link_libraries(producer ${LIBRT})
target_link_libraries(producer ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(consumer ${LIBRT})
target_link_libraries(consumer ${CMAKE_THREAD_LIBS_INIT})
