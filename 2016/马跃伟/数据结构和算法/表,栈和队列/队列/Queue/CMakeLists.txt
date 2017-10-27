cmake_minimum_required(VERSION 3.7)
project(Queue)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c queue.c queue.h)
add_executable(Queue ${SOURCE_FILES})