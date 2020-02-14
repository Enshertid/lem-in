/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 21:49:01 by dbendu            #+#    #+#             */
/*   Updated: 2020/02/05 12:43:02 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void					shift_map(t_data *data, int x, int y)
{
	t_room				*room;
	size_t				rooms_amount;
	size_t				iter;

	data->camera.x += x;
	data->camera.y += y;
	data->graph.center.x += x;
	data->graph.center.y += y;
	room = data->graph.rooms;
	rooms_amount = vec_size(room);
	iter = 0;
	while (iter < rooms_amount)
	{
		room->coord.x += x;
		room->coord.y += y;
		++iter;
		++room;
	}
	shift_ants(data, x, y);
}
