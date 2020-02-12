/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra_modifide.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 16:12:02 by ymanilow          #+#    #+#             */
/*   Updated: 2020/02/11 19:31:14 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void				get_way1(t_graph *graph, t_way *way)
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
//		way_point_add(way, way_point_create(tmp));
		i = -1;
		while (++i < graph->iter.col)
		{
			graph->rooms[i]->fork[0].prev_in_algo = NULL;
			graph->rooms[i]->fork[1].prev_in_algo = NULL;
			graph->rooms[i]->fork[0].distance = MAX_INT;
			graph->rooms[i]->fork[1].distance = MAX_INT;
			graph->rooms[i]->fork[0].flag = TRUE;
			graph->rooms[i]->fork[1].flag = TRUE;
			j = -1;
			while (++j < graph->rooms[i]->fork[0].iter.col - 1)
			{
				graph->rooms[i]->fork[0].links[j].status = TRUE;
				graph->rooms[i]->fork[1].links[j].status = TRUE;
			}
		}
		graph->rooms[0]->fork[0].distance = 0;
		graph->rooms[0]->fork[1].distance = 0;
		i = -1;
		while (++i < graph->rooms[0]->fork->iter.col - 1)
			graph->rooms[0]->fork->links[i].status = TRUE;
}

void					search_graph_for_way_with_common_links(t_graph *graph, t_turn *turn, t_way *way)
{
	int				i;

	turn_add(turn, &graph->rooms[0]->fork[0], FALSE);
	while (turn->arr[0])
	{
		i = -1;
		if (turn->arr[0]->in_out)
		{
			while (++i < turn->arr[0]->iter.col)
			{
				if (turn->arr[0]->links[i].status && !turn->arr[0]->flag &&
					turn->arr[0]->links[i].link->room != graph->rooms[0] &&
					turn->arr[0]->room != graph->rooms[graph->iter.col - 1])
				{
					if (turn->arr[0]->num_of_way == turn->arr[0]->links[i].link->num_of_way
					&& turn->arr[0]->distance - 1 < turn->arr[0]->links[i].link->distance)
					{
						turn->arr[0]->links[i].link->distance = turn->arr[0]->distance - 1;
						turn->arr[0]->links[i].link->prev_in_algo = turn->arr[0];
						turn_add(turn, turn->arr[0]->links[i].link, FALSE);
					}
					else if ( turn->arr[0]->distance + 1 < turn->arr[0]->links[i].link->distance)
					{
						turn->arr[0]->links[i].link->distance = turn->arr[0]->distance + 1;
						turn->arr[0]->links[i].link->prev_in_algo = turn->arr[0];
						turn_add(turn, turn->arr[0]->links[i].link, FALSE);
					}
				}
			}
			turn_del(turn);
		}
		else
		{
			while (++i < turn->arr[0]->iter.col)
			{
				if (turn->arr[0]->links[i].status && turn->arr[0]->flag &&
					turn->arr[0]->links[i].link->room != graph->rooms[0] &&
					turn->arr[0]->room != graph->rooms[graph->iter.col - 1])
				{
					if (turn->arr[0]->distance + 1 < turn->arr[0]->links[i].link->distance)
					{
						turn->arr[0]->links[i].link->distance = turn->arr[0]->distance + 1;
						turn->arr[0]->links[i].link->prev_in_algo = turn->arr[0];
						turn_add(turn, turn->arr[0]->links[i].link, FALSE);
					}
				}
			}
			turn_del(turn);
		}
	}
	get_way1(graph, way);
}
