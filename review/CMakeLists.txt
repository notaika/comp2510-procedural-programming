cmake_minimum_required(VERSION 4.1)
project(review C)

# add_compile_options(-Wall -Wextra -g)

set(CMAKE_C_STANDARD 23)

add_executable(review main.c)
add_executable(structs structs.c)
add_executable(structs_prac structs_prac.c)
add_executable(pointers_prac pointers_prac.c)
add_executable(midterm midterm.c)