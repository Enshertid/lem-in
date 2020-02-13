/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   private_mark_ways.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 14:59:41 by user              #+#    #+#             */
/*   Updated: 2020/02/05 16:26:51 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private_data.h"
#include "animation.h"

static void		mark_rooms_as_visits(t_ant *ant, t_animation *animation,
										t_room *rooms)
{
	size_t		iter;

	iter = 0;
	while (iter < ant->rooms_in_way)
	{
		if (ant->way[iter] != &rooms[0] && ant->way[iter] != &rooms[1])
			vec_pushback(&animation->visited_rooms, &ant->way[iter]);
		ant->way[iter]->color = __BROWN;
		++iter;
	}
}

void			mark_ways(t_data *data)
{
	t_ant		*ants;
	int			iter;

	data->animation.visited_rooms = vec_init(0, 1, sizeof(t_room*));
	ants = data->animation.ants;
	iter = 0;
	while (iter < data->animation.ants_amount)
	{
		mark_rooms_as_visits(ants, &data->animation, data->graph.rooms);
		++iter;
		++ants;
	}
}