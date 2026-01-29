cmake_minimum_required(VERSION 4.1)
project(lectures C)
add_compile_options(-Wall -Wextra -g)
# add_compile_options(-Wall -Wextra -Werror)

set(CMAKE_C_STANDARD 23)

add_executable(main main.c)

# week 1
add_executable(scanf week_one/scanf.c)
add_executable(fundamentals week_one/fundamentals.c)

# week 2
add_executable(arrays week_two/arrays.c)
add_executable(strings week_two/strings.c)
add_executable(switch week_two/switch.c)

# week 3
# nothing.. he cancelled

# week 4
add_executable(pointers week_four/pointers.c)