cmake_minimum_required(VERSION 4.1)
project(lab_5_notaika C)

add_compile_options(-Wall -Wextra -g)

set(CMAKE_C_STANDARD 23)

add_executable(lab_5_notaika lab6.c)

add_executable(debugging debugging.c)