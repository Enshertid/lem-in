/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suurballe_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 21:16:18 by ymanilow          #+#    #+#             */
/*   Updated: 2020/02/10 18:07:29 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void						 set_ways_to_the_next_iteration(t_ways *prev, t_ways *new)
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

void				get_ready_room_of_way(t_room *room, t_room *prev)
{
	room->fork->iter.i = -1;
	while (++room->fork[0].iter.i < room->fork[0].iter.col)
	{
		room->fork[0].prev_in_algo = NULL;
		room->fork[1].prev_in_algo = NULL;
		if (room->fork[0].links[room->fork[0].iter.i].link->room == prev)
			room->fork[0].links[room->fork[0].iter.i].status = TRUE;
		else
			room->fork[0].links[room->fork[0].iter.i].status = FALSE;
	}
}

void				wrap_directions(t_way *way, int num_of_way)
{
	t_way_room			*tmp;
	ssize_t				i;

	tmp = way->head;
	while (tmp->next)
	{
		i = -1;

		while (++i < tmp->room->fork->iter.i)
			if (tmp->room->fork[0].links[i].link->room == tmp->next->room)
			{
				tmp->room->fork[0].prev_in_algo = NULL;
				tmp->room->fork[1].prev_in_algo = NULL;
				tmp->room->fork[0].num_of_way = num_of_way;
				tmp->room->fork[1].num_of_way = num_of_way;
				tmp->room->flags.flag_of_way = TRUE;
			}
		tmp = tmp->next;
	}
	way->head->room->flags.flag_of_way = FALSE;
	way->tail->room->flags.flag_of_way = FALSE;
//	way->head->room->num_of_way = 0;
//	way->tail->room->num_of_way = 0;
}
