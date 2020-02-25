/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   private_create_rooms_map.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 19:27:08 by user              #+#    #+#             */
/*   Updated: 2020/02/25 22:07:41 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private_graph.h"
#include "vector.h"

t_map			create_rooms_map(t_room *rooms)
{
	t_map		map;
	size_t		rooms_amount;
	size_t		iter;
	t_room		*room;

	rooms_amount = vec_size(rooms);
	map = map_create(rooms_amount);
	iter = 0;
	room = rooms;
	while (iter < rooms_amount)
	{
		map_insert(&map, room->name, room);
		++iter;
		++room;
	}
	return (map);
}
