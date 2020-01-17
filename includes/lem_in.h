/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 19:07:02 by ymanilow          #+#    #+#             */
/*   Updated: 2020/01/17 16:08:59 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN
#define LEM_IN

#include "libft.h"

typedef struct			s_iters
{
	int					col;
	int					iter;
}						t_iters;

typedef struct			s_coord
{
	int					x;
	int					y;
}						t_coord;

typedef struct			s_flags
{
	t_bool				flag_end;
	t_bool				flag_link;
	t_bool				flag_ants;
	t_bool				flag_room;
	t_bool				flag_start;
	t_bool				flag_not_error_link1;
	t_bool				flag_not_error_link2;
}						t_flags;


typedef struct			s_room
{
	char				*name;
	t_iters				iters;
	t_coord				coord;
	t_bool				link_presence;
	t_bool				flag_of_presence;
	int					num_of_room;
	int					num_on_the_search;
	int					num_on_array;
	struct s_room		*prev_way;
	struct s_room		**links;
}						t_room;

typedef struct			s_turn_array
{
	t_room				**array;
	int					col;
	int					i;
	int					j;
	int					count;
}						t_turn_array;

typedef struct			s_turn_list
{
	t_room				*room;
	struct s_turn_list	*next;
	struct s_turn_list	*last;
}						t_turn_list;

typedef struct			s_way
{
	t_room				*room;
	struct s_way		*next;
	struct s_way		*prev;
}						t_way;

typedef struct			s_data
{
	t_room				*graph;
	t_room				*copy;
	t_room				end;
	t_flags				flags;
	t_iters				iters;
	t_way				*shortest_way;
	int					ants;
	int					fd;
}						t_data;

void					ft_parsing(char **av, t_data *data);
void					ft_pars_rooms(t_data *data);

void					ft_check_room(t_data *data, char **line);
void					ft_check_links(t_data *data, char **line);
void					ft_check_end(t_data *data, char **line);
void					ft_check_start(t_data *data, char **line);

void 					add_to_end_of_turn(t_turn_array *turn, t_room *new, int num);
void					delete_from_start(t_turn_array *turn);

void					dijkstra_list(t_data *data);
void					bfs_array(t_data *data);

void					data_first_set(t_data *data);
void					free_data(t_data *data);

#endif //LEM_IN
