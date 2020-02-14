/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_ants_moving.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 21:55:30 by dbendu            #+#    #+#             */
/*   Updated: 2020/02/05 12:40:34 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animation.h"
#include "data.h"

static void		setup_ant(t_ant *ant, float ticks)
{
	t_room		*cur_room;
	t_room		*next_room;

	cur_room = ant->way[ant->cur_room];
	next_room = ant->way[ant->cur_room + 1];
	ant->cur_x = cur_room->coord.x;
	ant->cur_y = cur_room->coord.y;
	ant->x_offset = (next_room->coord.x - cur_room->coord.x) / ticks;
	ant->y_offset = (next_room->coord.y - cur_room->coord.y) / ticks;
	++ant->cur_room;
}

void			setup_ants_moving(t_data *data)
{
	int			iter;
	t_ant		*ant;

	ant = data->animation.ants;
	iter = -1;
	while (++iter < data->animation.ants_amount)
	{
		if (ant->start_day > data->animation.cur_day)
			break ;
		if (ant->start_day == data->animation.cur_day)
		{
			--data->animation.ants_at_start;
			ant->is_active = TRUE;
		}
		if (ant->is_active && ant->cur_room + 1 == ant->rooms_in_way)
		{
			++data->animation.ants_at_finish;
			ant->is_active = FALSE;
		}
		if (ant->is_active)
			setup_ant(ant, data->animation.ticks);
		++ant;
	}
}
