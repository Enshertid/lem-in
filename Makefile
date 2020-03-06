# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/14 10:58:26 by ymanilow          #+#    #+#              #
#    Updated: 2020/03/06 14:40:14 by ymanilow         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_LEM = lem-in

NAME_VIZ = viz

DIR_L_S = srcs_lem

DIR_V_S = srcs_viz

DIR_L_O = obj_lem

DIR_V_O = obj_viz

DIR_L_H = includes_lem/

DIR_V_H = includes_viz/

LIB = ./libft/

LIB_V = -Iminilibx_macos -L minilibx_macos -lmlx -framework OpenGL -framework AppKit

FLAGS_L = -g -Wall -Wextra -Werror -I$(DIR_L_H) -I$(LIB)includes_l -I$(LIB)includes_p

FLAGS_V = -g -Wall -Wextra -Werror -I$(DIR_V_H) -I$(LIB)includes_l -I$(LIB)includes_p

SRCS_L = lem_in.c	parsing.c	pars_rooms.c	pars_links.c	remalloc_parsing.c	\
hash_table.c	hash_table_malloc.c	graph.c		get_next_line1.c	suurballe_algo.c\
search_of_shortest_way.c	ways.c		ways_operations.c	turn.c	algo.c\
dijkstra_modifide.c		fill_fork.c		throw_links.c	private_buf_storage.c\
buf_add_chr.c	buf_add_str.c	buf_destroy.c	buf_flush_to.c	buf_flush.c\
buf_get.c		buf_init.c		print.c		helpful_functions.c	check_repeat.c	costyl.c\

SRCS_V =		animation.c								move_ants.c					print_ants.c			\
				rotate_ants.c							setup_ants_moving.c			shift_ants.c			\
				private_get_ants_ways.c					animation_create.c			animation_destroy.c	\
				keyboard.c								mouse.c						data_create.c			\
				data_destroy.c							graph_create.c				graph_destroy.c			\
				private_get_rooms_and_coords.c			hashtable_find.c			private_add_z.c			\
				private_create_rooms_map.c				hashtable_create.c			private_get_flags.c		\
				private_get_links.c						draw_map.c					private_create_links.c		\
				hashtable_destroy.c						hashtable_insert.c			hashtable_private.c	\
				print_map.c								put_info.c					rotate_map.c				\
				move_map.c								private_del_dead_lines.c	tree_create.c				\
				tree_destroy.c							tree_find.c					tree_insert.c				\
				wnd.c									private_mark_ways.c			private_apply_flags.c		\
				private_draw_line.c						exit.c						main.c						\
				vector1.c								vector2.c					vector3.c	ft_my_itoa.c		get_next_line.c		malloc.c


SRCS_L_O = $(addprefix $(DIR_L_O)/,$(SRCS_L:.c=.o))

SRCS_V_O = $(addprefix $(DIR_V_O)/,$(SRCS_V:.c=.o))

all:$(NAME_LEM) $(NAME_VIZ)

$(DIR_L_O)/%.o: $(DIR_L_S)/%.c
	@mkdir -p $(DIR_L_O)
	@$(CC) $(FLAGS_L) -o $@ -c $<

$(DIR_V_O)/%.o: $(DIR_V_S)/%.c
	@mkdir -p $(DIR_V_O)
	@$(CC) $(FLAGS_V) -o $@ -c $<

$(NAME_LEM): $(SRCS_L_O)
	make -C $(LIB)
	$(CC) $(FLAGS_L) $(LIB)libft.a $(SRCS_L_O) -o $(NAME_LEM)

$(NAME_VIZ): $(SRCS_V_O)
	make -C $(LIB)
	make -C minilibx_macos
	$(CC) $(FLAGS_V) $(LIB)libft.a $(LIB_V)  $(SRCS_V_O) -o $(NAME_VIZ)

clean:
	@make clean -C $(LIB)
	@rm -Rf $(SRCS_L_O)
	@rm -Rf $(SRCS_V_O)
	@rm -Rf $(DIR_L_O)
	@rm -Rf $(DIR_V_O)

fclean: clean
	@make fclean -C $(LIB)
	@rm -Rf $(NAME_LEM)
	@rm -Rf $(NAME_VIZ)

re: fclean all
