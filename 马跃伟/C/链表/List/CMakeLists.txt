cmake_minimum_required(VERSION 3.7)
project(List)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c list.c)
add_executable(List ${SOURCE_FILES})