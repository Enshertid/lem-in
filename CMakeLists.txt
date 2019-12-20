cmake_minimum_required(VERSION 3.14)
project(lem_in C)

set(CMAKE_C_STANDARD 99)

include_directories(.)
include_directories(libft/includes/)
include_directories(minilibx/)

add_executable(lem_in main.c getmap.c vizu.h keyboard.c)

target_link_libraries(lem_in ${CMAKE_SOURCE_DIR}/libft/glibft.a)
target_link_libraries(lem_in ${CMAKE_SOURCE_DIR}/minilibx/libmlx.a)

target_link_libraries(lem_in "-lXext -lX11")
