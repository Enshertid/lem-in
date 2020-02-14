/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suurballe_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 21:16:18 by ymanilow          #+#    #+#             */
/*   Updated: 2020/02/14 05:39:49 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void						set_ways_to_the_next_iteration(t_ways *prev,
									t_ways *new)
{
	prev->iters.i = -1;
	new->iters.i = -1;
	while (++prev->iters.i < prev->iters.col)
	{
		get_copy_of_way(&prev->way_ar[prev->iters.i],
						&new->way_ar[prev->iters.i]);
		new->iters.i++;
	}
	new->iters.i++;
}

void						get_ready_room_of_way(t_room *room,
									t_room *prev, t_room *next, int num_of_way)
{
	int				i;

	i = -1;
	while (++i < room->fork[0].iter.col)
	{
		if (i == room->fork[0].iter.col - 1)
		{
			room->fork[0].links[i].link = &prev->fork[1];
			room->fork[0].links[i].status = TRUE;
		}
		else
			room->fork[0].links[i].status = FALSE;
	}
	i = -1;
	while (++i < room->fork[1].iter.col)
	{
		if (room->fork[1].links[i].link->room == prev ||
				room->fork[1].links[i].link->room == next)
			room->fork[1].links[i].status = FALSE;
	}
	room->fork[0].num_of_way = num_of_way;
	room->fork[1].num_of_way = num_of_way;
}

void						wrap_directions(t_way *way, int num_of_way)
{
	t_way_room			*tmp;
	int					i;

	tmp = way->head;
	i = -1;
	while (++i < tmp->room->fork[0].iter.i)
	{
		if (tmp->room->fork->links[i].link->room == tmp->next->room)
			tmp->room->fork->links[i].status = FALSE;
	}
	tmp = tmp->next;
	while (tmp->next)
	{
		get_ready_room_of_way(tmp->room, tmp->prev->room,
							tmp->next->room, num_of_way);
		tmp = tmp->next;
	}
	tmp->room->fork[0].prev_in_algo = NULL;
}
