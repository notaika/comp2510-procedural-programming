cmake_minimum_required(VERSION 4.1)
project(lab_7_notaika C)

add_compile_options(-Wall -Wextra -g)

set(CMAKE_C_STANDARD 23)

#main
add_executable(lab_7_notaika main.c)

#lab7
add_executable(lab7 lab7.c)