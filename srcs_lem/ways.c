/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ways.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 23:04:20 by ymanilow          #+#    #+#             */
/*   Updated: 2020/03/06 18:20:56 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ways.h"

int							way_weight(t_way *way)
{
	t_way_room				*tmp;

	way->weight = -1;
	tmp = way->head;
	while (tmp->next)
	{
		tmp = tmp->next;
		way->weight++;
	}
	way->weight++;
	return (way->weight);
}

t_way_room					*way_point_create(t_room *room)
{
	t_way_room				*point;

	point = ft_memalloc(sizeof(t_way_room));
	point->room = room;
	return (point);
}

void						way_point_add(t_way *storage, t_way_room *new)
{
	if (storage->head)
	{
		storage->head->prev = new;
		new->next = storage->head;
		storage->head = new;
	}
	else
	{
		storage->head = new;
		storage->tail = new;
	}
}

void						way_storage_set(t_graph *graph,
													t_storage_w *ways)
{
	int						i;

	ways->iters.col = graph->rooms[0]->fork[0].iter.i + 1;
	if (ways->iters.col > graph->rooms[graph->iter.col - 1]->fork[0].iter.i + 1)
		ways->iters.col = graph->rooms[graph->iter.col - 1]->fork[0].iter.i + 1;
	ways->ways = ft_memalloc(sizeof(t_ways) * ways->iters.col);
	i = -1;
	while (++i < ways->iters.col)
	{
		ways->ways[i].iters.col = i + 1;
		ways->ways[i].way_ar = ft_memalloc(sizeof(t_way) * ways->ways[i].
																	iters.col);
	}
}

void						way_storage_free(t_storage_w *ways)
{
	t_way_room				*tmp;
	t_way_room				*tmp1;
	int						i;

	i = -1;
	while (++i < ways->iters.col)
	{
		if (ways->ways[i].flag)
		{
			ways->ways[i].iters.i = -1;
			while (++ways->ways[i].iters.i <
					ways->ways[i].iters.col)
			{
				tmp = ways->ways[i].way_ar[ways->ways[i].iters.i].head;
				while (tmp)
				{
					tmp1 = tmp;
					tmp = tmp->next;
					ft_memset(tmp1, 0, sizeof(t_way_room));
					free(tmp1);
				}
			}
		}
		free(ways->ways[i].way_ar);
	}
	free(ways->ways);
}
