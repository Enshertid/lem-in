cmake_minimum_required(VERSION 3.14)
project(lem_in C)

set(CMAKE_C_STANDARD 99)

SET(CMAKE_C_FLAGS "-Wall -Werror -Wextra")

include_directories(.)
include_directories(libft/includes)
include_directories(minilibx)

add_executable(lem_in main.c keyboard.c input/get_input.c vizu.h draw_line.c libft/includes/libft.h input/get_graph.c exit.c mouse.c animation.c)


target_link_libraries(lem_in ${CMAKE_SOURCE_DIR}/libft/glibft.a)
target_link_libraries(lem_in ${CMAKE_SOURCE_DIR}/minilibx/libmlx.a)
target_link_libraries(lem_in "-lXext -lX11 -lm")