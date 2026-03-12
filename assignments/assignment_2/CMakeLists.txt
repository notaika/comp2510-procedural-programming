cmake_minimum_required(VERSION 4.1)
project(assignment_2 C)

add_compile_options(-Wall -Wextra -g)

set(CMAKE_C_STANDARD 23)

add_executable(assignment_2 main.c
        snacks.h
        snacks.c)

