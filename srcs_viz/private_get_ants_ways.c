/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   private_get_ants_ways.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 17:49:57 by user              #+#    #+#             */
/*   Updated: 2020/02/25 21:40:49 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private_animation.h"
#include "vector.h"
#include "lemin.h"

static void		add_ways(t_map *rooms_map, t_ant *ants, char *str, int day)
{
	char		*iter;
	int			ant_name;
	t_room		*room;

	while (str && *str)
	{
		ant_name = ft_atoi(str + 1);
		str = ft_strchr(str, '-') + 1;
		iter = ft_strchr(str, ' ');
		if (iter)
			*iter = '\0';
		room = map_find(rooms_map, str);
		vec_pushback(&(ants[ant_name - 1].way), &room);
		if (!ants[ant_name - 1].start_day)
			ants[ant_name - 1].start_day = day;
		str = iter;
		if (str)
			++str;
	}
}

static t_ant	*ants_init(int ants_amount, t_room *start)
{
	t_ant		*ants;
	t_ant		*ant;
	int			iter;

	ants = vec_init(0, ants_amount, sizeof(t_ant));
	ft_memset(ants, 0, sizeof(t_ant) * ants_amount);
	iter = -1;
	ant = ants;
	while (++iter < ants_amount)
	{
		ant->way = vec_init(0, 2, sizeof(t_room*));
		vec_pushback(&ant->way, &start);
		++ant;
	}
	return (ants);
}

t_ant			*get_ants_ways(int ants_amount, t_map *rooms_map, t_room *rooms)
{
	t_ant		*ants;
	t_ant		*ant;
	char		*str;
	int			day;
	int			iter;

	ants = ants_init(ants_amount, &rooms[0]);
	day = 1;
	while (get_next_line(0, &str) == 1)
	{
		if (*str != '#')
		{
			add_ways(rooms_map, ants, str, day);
			++day;
		}
		free(str);
	}
	ant = ants;
	iter = -1;
	while (++iter < ants_amount)
	{
		ant->rooms_in_way = vec_size(ant->way);
		++ant;
	}
	return (ants);
}
