/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 19:07:02 by ymanilow          #+#    #+#             */
/*   Updated: 2019/12/19 23:06:20 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN
#define LEM_IN

#include "libft.h"

# define START			MIN_INT
# define FINISH			-1

typedef struct			s_room
{
	char				*name;
	int					width;
	int					hight;
	int					num_of_room;
	int					col;
	int					iter;
	t_bool				link_presence;
	t_bool				ant_presence;
	struct s_room		*links;
}						t_room;

typedef struct			s_data
{
	t_room				*rooms;
	t_room				end;
	t_bool				flag_start;
	t_bool				flag_end;
	t_bool				flag_link;
	t_bool				flag_ants;
	t_bool				flag_comment;
	t_bool				flag_not_error_link1;
	t_bool				flag_not_error_link2;
	int					ants;
	int					num_of_rooms;
	int					col;
}						t_data;

void					ft_parsing(int ac, char **av, t_data *data);

void					ft_pars_rooms(t_data *data);
void					ft_check_room(t_data *data, char **line);
void					ft_check_links(t_data *data, char **line);
void					ft_check_end(t_data *data, char **line, int fd);
void					ft_check_start(t_data *data, char **line, int fd);

char					**ft_strsplit_1(char const *s, char c);
char					**ft_free(char **str, size_t i);

#endif //LEM_IN
