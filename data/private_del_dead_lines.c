/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   private_del_dead_lines.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 13:01:06 by user              #+#    #+#             */
/*   Updated: 2020/02/05 13:43:06 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include <stdio.h>

#include "private_data.h"

static void		add_links_to_rooms(t_data *data)
{
	t_link		*links;
	t_room		*room1;
	t_room		*room2;
	size_t		links_amount;
	size_t		iter;

	links = data->graph.links;
	links_amount = vec_size(links);
	iter = 0;
	while (iter < links_amount)
	{
		room1 = map_find(&data->graph.rooms_map, links->room1->name);
		room2 = map_find(&data->graph.rooms_map, links->room2->name);
		if (!room1->links)
			room1->links = vec_init(0, 1, sizeof(t_room*));
		vec_pushback(&room1->links, &room2);
		if (!room2->links)
			room2->links = vec_init(0, 1, sizeof(t_room*));
		vec_pushback(&room2->links, &room1);
		++iter;
		++links;
	}
}

static void		del_links_from_rooms(t_data *data)
{
	size_t		iter;
	t_room		*rooms;
	size_t		rooms_amount;

	rooms = data->graph.rooms;
	rooms_amount = vec_size(rooms);
	iter = 0;
	while (iter < rooms_amount)
	{
		if (rooms->links)
			vec_clear(&rooms->links);
		++rooms;
		++iter;
	}
}

static void		del_room(t_data *data, size_t pos)
{
	t_room		*room;
	size_t		iter;
	t_link		*links;

	room = &data->graph.rooms[pos];
	links = data->graph.links;
	iter = 0;
	while (TRUE)
	{
		if (links[iter].room1 == room || links[iter].room2 == room)
		{
			vec_delelem(&links, iter);
			break;
		}
		++iter;
	}
	// vec_delelem(&data->graph.rooms, pos);
}

void			del_dead_lines(t_data *data)
{
	size_t		iter;
	size_t		rooms_amount;
	t_room		*rooms;

	add_links_to_rooms(data);
	for (size_t i = 0; i < vec_size(data->graph.links); ++i)
		printf("%s - %s\n", data->graph.links[i].room1->name, data->graph.links[i].room2->name);
	// for (size_t i =0; i < vec_size(data->graph.rooms); ++i)
	// {
	// 	if (data->graph.rooms[i].links)
	// 	{
	// 		printf("%s\n", data->graph.rooms[i].name);
	// 		for (size_t j = 0; j < vec_size(data->graph.rooms[i].links); ++j)
	// 		{
	// 			printf("---> %s\n", data->graph.rooms[i].links[j]->name);
	// 		}
	// 		printf("\n");
	// 	}
	// }
	rooms = data->graph.rooms;
	rooms_amount = vec_size(rooms);
	iter = 2;
	while (iter < rooms_amount)
	{
		if (!rooms[iter].links || vec_size(rooms[iter].links) == 1)
		{
			del_room(data, iter);
		}
		++iter;
	}
	del_links_from_rooms(data);
	printf("\n\n");
	for (size_t i = 0; i < vec_size(data->graph.links); ++i)
		printf("%s - %s\n", data->graph.links[i].room1->name, data->graph.links[i].room2->name);
}
