cmake_minimum_required(VERSION 3.21)
project(TP2 C)

set(CMAKE_C_STANDARD 99)
set(SOURCE_FILES codigo/permuta.c codigo/permuta.h)

add_executable(main ${SOURCE_FILES})
