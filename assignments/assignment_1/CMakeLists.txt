cmake_minimum_required(VERSION 4.1)
project(assignment_1 C)
add_compile_options(-Wall -Wextra -g)

set(CMAKE_C_STANDARD 23)

add_executable(assignment_1
        main.c
        streditor.c)
