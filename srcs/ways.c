/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ways.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 23:04:20 by ymanilow          #+#    #+#             */
/*   Updated: 2020/01/24 22:42:11 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ways.h"

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

void						way_storage_set(t_graph *graph, t_storage_w *ways)
{
	int						i;

	ways->iters.i = -1;
	ways->iters.col = graph->rooms[0]->iter.i;
	if (ways->iters.col > graph->rooms[graph->iter.col - 1]->iter.i)
		ways->iters.col = graph->rooms[graph->iter.col - 1]->iter.i;
	ways->ways = ft_memalloc(sizeof(t_ways) * ways->iters.col);
	i = -1;
	while (++i < ways->iters.col)
	{
		ways->ways[i].iters.col = i + 1;
		ways->ways[i].way_ar = ft_memalloc(sizeof(t_way) * ways->ways[i].iters.col);
	}
}

void						way_clear(t_way *way)
{
	t_way_room				*tmp;
	t_way_room				*tmp_s;

	tmp = way->head;
	tmp_s = way->head;
	while (tmp)
	{
		tmp = tmp->next;
		tmp_s->prev = NULL;
		tmp_s->next = NULL;
		free(tmp_s);
		tmp_s = tmp;
	}
	way->head = NULL;
	way->tail = NULL;
}