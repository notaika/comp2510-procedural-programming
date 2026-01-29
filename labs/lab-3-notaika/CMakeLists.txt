cmake_minimum_required(VERSION 4.1)
project(lab_3_notaika C)

add_compile_options(-Wall -Wextra -g)

set(CMAKE_C_STANDARD 23)

add_executable(lab_3_notaika
        main.c
        guardian.c)
