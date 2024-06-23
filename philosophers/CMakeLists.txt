cmake_minimum_required(VERSION 3.28)
project(philosophers C)

set(CMAKE_C_STANDARD 11)

# Recursively collect all .c files from the current directory and its subdirectories
file(GLOB_RECURSE SRC_FILES ${CMAKE_SOURCE_DIR}/srcs/*.c, ${CMAKE_SOURCE_DIR}/libft/*.c)

add_executable(philosophers ${SRC_FILES}
        srcs/philo_action.c
        srcs/main.c
        srcs/initialize.c
        srcs/philo_utils.c)