/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 19:07:02 by ymanilow          #+#    #+#             */
/*   Updated: 2019/12/23 23:02:05 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN
#define LEM_IN

#include "libft.h"

# define START			MIN_INT
# define FINISH			-1

typedef struct			s_void
{
	void				*data;
	struct s_void		*next;
}						t_void;

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
	t_bool				ant_presence;
	t_bool				link_presence;
	t_bool				flag_of_presence;
	int					num_of_room;
	int					num_of_prev_room;
	int					num_on_the_search;
	struct s_room		**links;
}						t_room;

typedef struct			s_ways
{
	int					iter;
	int					col;
	t_room				*way;
}						t_ways;

typedef struct			s_turn_array
{
	t_room				**turn_array;
	int					col;
	int					iter;
}						t_turn_array;

typedef struct			s_data
{
	t_room				*rooms;
	t_turn_array		turn;
	t_room				end;
	t_room				tmp;
	t_flags				flags;
	t_iters				iters;
	int					ants;
	int					fd;
}						t_data;

void					ft_parsing(char **av, t_data *data);

void					ft_pars_rooms(t_data *data);
void					ft_check_room(t_data *data, char **line);
void					ft_check_links(t_data *data, char **line);
void					ft_check_end(t_data *data, char **line);
void					ft_check_start(t_data *data, char **line);
void					pop_front(t_data *data);
void					*ft_malloc_store(size_t size);
void 					ft_free_storage();

#endif //LEM_IN
