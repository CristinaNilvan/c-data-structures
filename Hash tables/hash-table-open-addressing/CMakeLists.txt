cmake_minimum_required(VERSION 3.17)
project(hash_table_open_addressing C)

set(CMAKE_C_STANDARD 99)

add_executable(hash_table_open_addressing main.c hash_table.c hash_table.h)