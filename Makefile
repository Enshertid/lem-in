SRCS = main.c keyboard.c getmap.c

all:
	@clear
	@gcc -g -Wall -Werror -Wextra $(SRCS) -I. -Ilibft/includes libft/glibft.a -L minilibx_macos -I minilibx_macos 	-lmlx -framework OpenGL -framework AppKit -framework OpenCL
	@clear
