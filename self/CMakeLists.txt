cmake_minimum_required(VERSION 4.1)
project(self C)

set(CMAKE_C_STANDARD 23)

add_executable(self main.c)

# ch7
add_executable(char_types ch7/char_types.c)

# ch8
add_executable(one_d_arrays ch8/one_d_arrays.c)
add_executable(two_d_arrays ch8/two_d_arrays.c)

# ch11
add_executable(pointers.c ch11/pointers.c)