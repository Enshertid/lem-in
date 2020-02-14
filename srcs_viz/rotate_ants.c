/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ants.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <dbendu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 21:54:05 by dbendu            #+#    #+#             */
/*   Updated: 2020/02/14 01:30:34 by dbendu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animation.h"
#include "data.h"

static void				setup_ant(t_ant *ant, float ticks, int cur_tick)
{
	t_room		*cur_room;
	t_room		*next_room;

	cur_room = ant->way[ant->cur_room - 1];
	next_room = ant->way[ant->cur_room];
	ant->x_offset = (next_room->coord.x - cur_room->coord.x) / ticks;
	ant->y_offset = (next_room->coord.y - cur_room->coord.y) / ticks;
	ant->cur_x = cur_room->coord.x + ant->x_offset * cur_tick;
	ant->cur_y = cur_room->coord.y + ant->y_offset * cur_tick;
}

void					rotate_ants(t_data *data)
{
	int			iter;
	t_ant		*ant;

	if (data->animation.ants_at_start == data->animation.ants_amount ||
		data->animation.ants_at_finish == data->animation.ants_amount)
		return ;
	iter = 0;
	ant = data->animation.ants;
	while (iter < data->animation.ants_amount)
	{
		if (ant->start_day > data->animation.cur_day)
			break ;
		if (ant->is_active)
			setup_ant(ant, data->animation.ticks, data->animation.cur_tick);
		++iter;
		++ant;
	}
}
