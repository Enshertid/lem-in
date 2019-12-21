/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 19:07:02 by ymanilow          #+#    #+#             */
/*   Updated: 2019/12/21 19:28:52 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN
#define LEM_IN

#include "libft.h"

# define COF 3
# define GNL_BUFF 1000

typedef struct			s_room
{
	char				*name;
	int					x;
	int					y;
	int					num_of_room;
	int					col;
	int					iter;
	t_bool				link_presence;
	t_bool				ant_presence;
	struct s_room		**links;
}						t_room;

typedef struct			s_data
{
	t_room				*rooms;
	t_room				end;
	t_bool				flag_end;
	t_bool				flag_link;
	t_bool				flag_ants;
	t_bool				flag_room;
	t_bool				flag_start;
	t_bool				flag_not_error_link1;
	t_bool				flag_not_error_link2;
	int					col;
	int					ants;
	int					num_of_rooms;
	int					fd;
}						t_data;

void					ft_parsing(char **av, t_data *data);

void					ft_add_end(t_data *data, char **line);
void					ft_add_room(t_data *data, char **line);
void					ft_add_start(t_data *data, char **line);
void					ft_check_rooms(t_data *data);
void					ft_check_links(t_data *data, char **line);

#endif //LEM_IN
