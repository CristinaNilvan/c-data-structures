cmake_minimum_required(VERSION 3.17)
project(graph_adjacency_matrix C)

set(CMAKE_C_STANDARD 99)

add_executable(graph_adjacency_matrix main.c queue.h queue.c)