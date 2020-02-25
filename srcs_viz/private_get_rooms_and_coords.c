/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   private_get_rooms_and_coords.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 02:15:11 by dbendu            #+#    #+#             */
/*   Updated: 2020/02/25 21:45:56 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private_graph.h"
#include "libft.h"
#include "lemin.h"
#include "vector.h"

static t_room			get_room(char *str)
{
	t_room		room;

	room.name = str;
	str = ft_strchr(str, ' ') + 1;
	str[-1] = '\0';
	room.name = ft_strdup(room.name);
	room.coord.x = ft_atoi(str);
	room.coord.y = ft_atoi(ft_strchr(str, ' ') + 1);
	room.coord.z = 0;
	room.links = NULL;
	room.color = __WHITE;
	return (room);
}

static void				get_tail(t_room *rooms, t_coord *basic_coords,
								char **str)
{
	t_bool		is_start;

	is_start = (*str)[2] == 's' ? 0 : 1;
	free(*str);
	while (TRUE)
	{
		get_next_line(0, str);
		if (**str != '#')
		{
			rooms[is_start ? 1 : 0] = get_room(*str);
			basic_coords[is_start ? 1 : 0] = rooms[is_start ? 1 : 0].coord;
			break ;
		}
		else
			free(*str);
	}
}

void					get_rooms_and_coords(t_graph *graph, char **str)
{
	t_room		room;

	graph->rooms = vec_init(0, 2, sizeof(t_room));
	graph->basic_coords = vec_init(0, 2, sizeof(t_coord));
	vec_set_size(graph->rooms, 2);
	vec_set_size(graph->basic_coords, 2);
	while (TRUE)
	{
		get_next_line(0, str);
		if (**str != '#' && !ft_strchr(*str, ' '))
			break ;
		if (**str != '#')
		{
			room = get_room(*str);
			vec_pushback(&graph->rooms, &room);
			vec_pushback(&graph->basic_coords, &room.coord);
		}
		else if (**str == '#' && (*str)[1] == '#')
			get_tail(graph->rooms, graph->basic_coords, str);
		free(*str);
	}
}
