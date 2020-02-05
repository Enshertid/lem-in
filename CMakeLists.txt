cmake_minimum_required(VERSION 3.15)
project(lem_in C)

set(CMAKE_C_STANDARD 11)

include_directories(includes)
include_directories(libft/includes_l)
include_directories(libft/includes_p)

add_executable(lem_in
        includes/graph.h
        includes/hash_table.h
        includes/lem_in.h
        includes/parsing.h
        includes/turn.h
        includes/ways.h
        srcs/get_next_line1.c
        srcs/graph.c
        srcs/hash_table.c
        srcs/hash_table_malloc.c
        srcs/lem_in.c
        srcs/pars_links.c
        srcs/pars_rooms.c
        srcs/parsing.c
        srcs/remalloc_parsing.c
        srcs/search_of_shortest_way.c
        srcs/suurballe_algo.c
        srcs/turn.c
        srcs/ways.c
        srcs/ways_operations.c srcs/garbage.c)

target_link_libraries(lem_in ~/curcus42/lem-in/libft/libft.a)