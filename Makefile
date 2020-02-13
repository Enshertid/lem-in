# SRCS = main.c draw_line.c exit.c control/*.c anim.c animation/*.c map/*.c map_actions/*.c ant/*.c tree/*.c room/*.c data/*.c graph/*.c wnd/*.c wnd_state/*.c libft/glibft.a minilibx_macos/libmlx.a

# H = -I coord -I room -I map/ -I tree/ -I data -I graph -I wnd -I wnd_state -I animation -I libft/includes -I ant -I map_actions -I minilibx_macos -framework OpenGL -framework AppKit

# all:
# 	clear
# 	gcc -g -Wall -Werror -Wextra $(SRCS) $(H)




SRCS =			animation/animation.c							animation/move_ants.c				animation/print_ants.c			\
				animation/rotate_ants.c							animation/setup_ants_moving.c		animation/shift_ants.c			\
				animation/private_get_ants_ways.c				animation/animation_create.c		animation/animation_destroy.c	\
				control/keyboard.c								control/mouse.c						data/data_create.c				\
				data/data_destroy.c								graph/graph_create.c				graph/graph_destroy.c			\
				graph/private_get_rooms_and_coords.c			hashtable/hashtable_find.c			data/private_add_z.c			\
				graph/private_create_rooms_map.c				hashtable/hashtable_create.c		data/private_get_flags.c		\
				graph/private_get_links.c						graph/private_setup_graph_center.c	data/private_create_links.c		\
				hashtable/hashtable_destroy.c					hashtable/hashtable_insert.c		hashtable/hashtable_private.c	\
				map/print_map.c									map/put_info.c						map/rotate_map.c				\
				map/move_map.c									data/private_del_dead_lines.c		tree/tree_create.c				\
				tree/tree_destroy.c								tree/tree_find.c					tree/tree_insert.c				\
				wnd/wnd.c										data/private_mark_ways.c			data/private_apply_flags.c		\
				map/private_draw_line.c							exit.c								main.c							\
				libft/glibft.a									minilibx_macos/libmlx.a				map/draw_map.c


HEADERS =		-I .				-I tree				-I wnd				\
				-I room				-I graph			-I hashtable		\
				-I data				-I coord			-I animation		\
				-I map


LIBS_HEADERS =	mlx.h			libft.h

FLAGS = -framework OpenGL -framework AppKit

#FLAGS = -lX11 -lXext

all:
	gcc -g -Wall -Werror -Wextra $(SRCS) $(HEADERS) -I libft/includes -I minilibx_macos $(FLAGS) -lm
