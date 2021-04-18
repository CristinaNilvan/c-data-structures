cmake_minimum_required(VERSION 3.17)
project(stack C)

set(CMAKE_C_STANDARD 99)

add_executable(stack main.c stack.c stack.h)