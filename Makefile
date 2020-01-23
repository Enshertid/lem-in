# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/14 10:58:26 by ymanilow          #+#    #+#              #
#    Updated: 2020/01/23 22:38:04 by ymanilow         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem_im

DIR_S = srcs

DIR_O = obj

DIR_H = includes/

LIB = ./libft/

FLAGS = -Wall -Wextra -Werror -I$(DIR_H) -I$(LIB)includes_l -I$(LIB)includes_p

SRCS_C = lem_in.c	parsing.c	pars_rooms.c	pars_links.c	remalloc_parsing.c	\
hash_table.c	hash_table_malloc.c	graph.c		get_next_line1.c					\


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
