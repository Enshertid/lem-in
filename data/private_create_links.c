/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   private_create_links.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 20:36:52 by user              #+#    #+#             */
/*   Updated: 2020/02/04 11:43:49 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private_data.h"

static void		get_links_from_room(t_link **links, t_room *room)
{
	size_t		links_amount;
	size_t		iter;
	t_room		**link;

	link = room->links;
	links_amount = vec_size(room->links);
	iter = 0;
	while (iter < links_amount)
	{
		if (*link > room)
			vec_pushback(links, link);
		++iter;
		++*link;
	}
}

t_link			*create_links(t_room *rooms)
{
	t_link		*links;
	size_t		rooms_amount;
	size_t		iter;
	t_room		*room;

	links = vec_init(0, 1, sizeof(t_link));
	rooms_amount = vec_size(rooms);
	room = rooms;
	iter = 0;
	while (iter < rooms_amount)
	{
		get_links_from_room(&links, room);
		++iter;
		++room;
	}
	return (links);
}