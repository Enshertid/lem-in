/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_of_shortest_way.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 13:54:43 by ymanilow          #+#    #+#             */
/*   Updated: 2020/02/12 15:36:08 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void					get_way(t_graph *graph, t_way *way)
{
	t_fork					*tmp;
	ssize_t					i;
	ssize_t					j;

	tmp = &graph->rooms[graph->iter.col - 1]->fork[0];
	while (tmp)
	{
		way_point_add(way, way_point_create(tmp->room));
		tmp = tmp->prev_in_algo;
	}
	i = -1;
	while (++i < graph->iter.col)
	{
		j = -1;
		while (++j < graph->rooms[i]->fork[0].iter.col - 1)
		{
			graph->rooms[i]->fork[0].links[j].link->room->flag = FALSE;
			graph->rooms[i]->fork[0].links[j].link->prev_in_algo = NULL;
			graph->rooms[i]->fork[0].links[j].link->distance = MAX_INT;
		}
	}
	graph->rooms[0]->fork[0].distance = 0;
}

void					dijkstra_algo(t_graph *graph, t_turn *turn, t_way *way)
{
	ssize_t				i;

	turn_add(turn, &graph->rooms[0]->fork[0], FALSE);
	while (turn->arr[0])
	{
		i = -1;
		while (++i < turn->arr[0]->iter.col)
			if (turn->arr[0]->links[i].status &&
				turn->arr[0]->distance + 1 <= turn->arr[0]->links[i].
				link->distance && !turn->arr[0]->flag)
			{
				turn->arr[0]->links[i].link->
									prev_in_algo = turn->arr[0];
				turn->arr[0]->links[i].link->distance =
										turn->arr[0]->distance + 1;
				turn_add(turn, turn->arr[0]->links[i].link, FALSE);
			}
		turn_del(turn);
	}
	get_way(graph, way);
}
