/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suurballe_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 21:16:18 by ymanilow          #+#    #+#             */
/*   Updated: 2020/01/25 18:41:49 by ymanilow         ###   ########.fr       */
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

void				wrap_directions(t_way *way)
{
	t_way_room			*tmp;
	ssize_t				i;

	tmp = way->head;
	while (tmp->next)
	{
		i = -1;
		while (++i < tmp->room->iter.i)
			if (tmp->room->links[i].link == tmp->next->room)
			{
				tmp->room->links[i].status = FALSE;
				tmp->room->flags.flag_of_way = TRUE;
			}
		tmp = tmp->next;
	}
	way->head->room->flags.flag_of_way = FALSE;
	way->tail->room->flags.flag_of_way = FALSE;
}
