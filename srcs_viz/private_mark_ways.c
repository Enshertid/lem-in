/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   private_mark_ways.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 14:59:41 by user              #+#    #+#             */
/*   Updated: 2020/02/26 18:40:48 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private_data.h"
#include "animation.h"

static int		need_add(t_room **rooms, t_room *find)
{
	size_t		room;
	size_t		rooms_amount;
	t_bool		need_to_add;

	room = 0;
	rooms_amount = vec_size(rooms);
	need_to_add = TRUE;
	while (room < rooms_amount)
	{
		if (rooms[room] == find)
		{
			need_to_add = FALSE;
			break ;
		}
		++room;
	}
	return (need_to_add);
}

static void		mark_rooms_as_visits(t_ant *ant, t_animation *animation,
										t_room *rooms)
{
	size_t		iter;

	iter = 0;
	while (iter < ant->rooms_in_way)
	{
		if (ant->way[iter] != &rooms[0] && ant->way[iter] != &rooms[1])
		{
			if (need_add(animation->visited_rooms, ant->way[iter]))
			{
				vec_pushback(&animation->visited_rooms, &ant->way[iter]);
				ant->way[iter]->color = __BROWN;
			}
		}
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
	data->animation.ants[0].way[0]->color = __BROWN;
	data->animation.ants[0].way[data->animation.ants[0].rooms_in_way - 1]
														->color = __BROWN;
}
