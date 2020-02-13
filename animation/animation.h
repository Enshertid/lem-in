/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 21:53:11 by dbendu            #+#    #+#             */
/*   Updated: 2020/02/05 15:49:27 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMATION_H
# define ANIMATION_H

# include "hashtable.h"
# include "room.h"
# include "wnd.h"

typedef struct s_data	t_data;

typedef struct		s_ant
{
	t_room			**way;
	int				name;
	float			cur_x;
	float			cur_y;
	int				start_day;
	float			x_offset;
	float			y_offset;
	size_t			cur_room;
	size_t			rooms_in_way;
	t_bool			is_active;
}					t_ant;

typedef struct		s_animation
{
	t_room			**visited_rooms;
	t_bool			is_animation_active;
	t_ant			*ants;
	int				ants_amount;
	int				ants_at_finish;
	int				ants_at_start;
	int				ticks;
	int				cur_tick;
	int				cur_day;
}					t_animation;

int					animation(t_data *data);

t_animation			animation_create(int ants, t_map *rooms_map, t_room *rooms);
void				animation_destroy(t_animation *animation);

void				shift_ants(t_data *data, int x, int y);
void				rotate_ants(t_data *data);
void				setup_ants_moving(t_data *data);
void				print_ants(t_data *data);
void				move_ants(t_data *data);

#endif
