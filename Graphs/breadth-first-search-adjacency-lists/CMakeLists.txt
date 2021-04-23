cmake_minimum_required(VERSION 3.17)
project(breadth_first_search_adjacency_lists C)

set(CMAKE_C_STANDARD 99)

add_executable(breadth_first_search_adjacency_lists main.c queue.c queue.h)