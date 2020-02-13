# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/14 10:58:26 by ymanilow          #+#    #+#              #
#    Updated: 2020/02/14 02:10:43 by ymanilow         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem_im

DIR_S = srcs

DIR_O = obj

DIR_H = includes/

LIB = ./libft/

FLAGS = -g -Wall -Wextra -Werror -I$(DIR_H) -I$(LIB)includes_l -I$(LIB)includes_p

SRCS_C = lem_in.c	parsing.c	pars_rooms.c	pars_links.c	remalloc_parsing.c	\
hash_table.c	hash_table_malloc.c	graph.c		get_next_line1.c	suurballe_algo.c\
search_of_shortest_way.c	ways.c		ways_operations.c	turn.c	algo.c\
dijkstra_modifide.c		fill_fork.c		throw_links.c	private_buf_storage.c\
buf_add_chr.c	buf_add_str.c	buf_destroy.c	buf_flush_to.c	buf_flush.c\
buf_get.c		buf_init.c		\


SRCS_O = $(addprefix $(DIR_O)/,$(SRCS_C:.c=.o))

all: $(NAME)

$(DIR_O)/%.o: $(DIR_S)/%.c
	@mkdir -p $(DIR_O)
	@$(CC) $(FLAGS) -o $@ -c $<

$(NAME): $(SRCS_O)
	@make -C $(LIB)
	$(CC) $(FLAGS) $(LIB)libft.a $(SRCS_O) -o $(NAME)

clean:
	@make clean -C $(LIB)
	@rm -Rf $(SRCS_O)
	@rm -Rf $(DIR_O)

fclean: clean
	@make fclean -C $(LIB)
	@rm -Rf $(NAME)

re: fclean all
