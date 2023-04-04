cmake_minimum_required(VERSION 3.25)
project(LABA14 C)

set(CMAKE_C_STANDARD 11)

add_executable(LABA14 main.c)

add_subdirectory(mother)
target_link_libraries(LABA14 data_structures)
target_link_libraries(LABA14 algorithms)
