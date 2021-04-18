cmake_minimum_required(VERSION 3.17)
project(binary_search_tree C)

set(CMAKE_C_STANDARD 99)

add_executable(binary_search_tree main.c binary_search_tree.c binary_search_tree.h)