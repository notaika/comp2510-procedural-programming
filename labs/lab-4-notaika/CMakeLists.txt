cmake_minimum_required(VERSION 4.1)
project(lab_4_notaika C)

add_compile_options(-Wall -Wextra -g)

set(CMAKE_C_STANDARD 23)

add_executable(lab5 lab5.c)
add_executable(debuggingTask debug_task_setC.c)
