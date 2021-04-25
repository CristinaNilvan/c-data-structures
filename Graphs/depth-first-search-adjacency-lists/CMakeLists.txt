cmake_minimum_required(VERSION 3.17)
project(depth_first_search_adjacency_lists C)

set(CMAKE_C_STANDARD 99)

add_executable(depth_first_search_adjacency_lists main.c stack.c stack.h)