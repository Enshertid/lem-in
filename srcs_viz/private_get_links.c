/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   private_get_links.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 20:51:27 by user              #+#    #+#             */
/*   Updated: 2020/02/26 16:51:50 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private_graph.h"
#include "vector.h"
#include "lemin.h"

static void			find_rooms(t_map *rooms_map, char *str,
										t_room **room1, t_room **room2)
{
	char		*name1;
	char		*name2;

	name1 = str;
	name2 = ft_strchr(str, '-') + 1;
	name2[-1] = '\0';
	*room1 = map_find(rooms_map, name1);
	*room2 = map_find(rooms_map, name2);
}

t_link				*get_links(t_map *rooms_map, char *str)
{
	t_link			*links;
	t_link			link;

	links = vec_init(0, 1, sizeof(t_link));
	while (TRUE)
	{
		if (*str != '#')
		{
			find_rooms(rooms_map, str, &link.room1, &link.room2);
			vec_pushback(&links, &link);
		}
		free(str);
		get_next_line(0, &str);
		if (!*str)
		{
			free(str);
			break ;
		}
	}
	return (links);
}
