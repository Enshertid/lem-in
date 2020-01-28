/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_of_shortest_way.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 13:54:43 by ymanilow          #+#    #+#             */
/*   Updated: 2020/01/26 16:39:38 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void					get_way(t_graph *graph, t_way *way)
{
	t_room					*tmp;
	ssize_t					i;
	ssize_t					j;

	tmp = graph->rooms[graph->iter.col - 1];
	while (tmp)
	{
		way_point_add(way, way_point_create(tmp));
		tmp = tmp->prev_in_algo[1].link;
	}
	i = -1;
	while (++i < graph->iter.col)
	{
		j = -1;
		while (++j < graph->rooms[i]->iter.i)
		{
			graph->rooms[i]->links[j].link->flags.flag = FALSE;
			graph->rooms[i]->links[j].link->prev_in_algo[1].link = NULL;
			graph->rooms[i]->links[j].link->distance = MAX_INT;
		}
		graph->rooms[i]->flags.flag_of_way = FALSE;
	}
	graph->rooms[0]->distance = 0;
}

void					dijkstra_algo(t_graph *graph, t_turn *turn, t_way *way)
{
		ssize_t						i;

		turn_add(turn, graph->rooms[0]);
		while(turn->arr[0])
		{
			i = -1;
			while(++i < turn->arr[0]->iter.i)
				if (turn->arr[0]->links[i].status &&
					turn->arr[0]->distance + 1 < turn->arr[0]->links[i].
					link->distance && !turn->arr[0]->links[i].condition)
				{
					turn->arr[0]->links[i].link->prev_in_algo[1].link
							= turn->arr[0];
					turn->arr[0]->links[i].link->distance = turn->arr[0]->
							distance + 1;
					if (!turn->arr[0]->links[i].link->flags.flag)
					{
						turn->arr[0]->links[i].link->flags.flag = 1;
						turn_add(turn, turn->arr[0]->links[i].link);
					}
				}
			turn_del(turn);
		}
		get_way(graph, way);
}

void					dijkstra_algo_modifide(t_graph *graph, t_turn *turn, t_way *way)
{
	ssize_t						i;

	turn_add(turn, graph->rooms[0]);
	while(turn->arr[0])
	{
		i = -1;
		while(++i < turn->arr[0]->iter.i)
		{
			if (turn->arr[0]->links[i].status &&
				turn->arr[0]->distance + 1 < turn->arr[0]->links[i].
						link->distance && !turn->arr[0]->links[i].condition)
			{
				if (turn->arr[0]->prev_in_algo[1].link && !turn->arr[0]->prev_in_algo[1].link->flags.flag_of_way &&
					turn->arr[0]->flags.flag_of_way && !turn->arr[0]->links[i].link->flags.flag_of_way)
					continue;
				else if ((turn->arr[0]->prev_in_algo[1].link && turn->arr[0]->prev_in_algo[1].link->flags.flag_of_way &&
					turn->arr[0]->flags.flag_of_way && turn->arr[0]->links[i].link->flags.flag_of_way))
					continue;
				turn->arr[0]->links[i].link->prev_in_algo[1].link
 						= turn->arr[0];
				turn->arr[0]->links[i].link->distance = turn->arr[0]->
						distance + 1;
//				turn->arr[0]->links[i].link->flags.flag = FALSE;
				if (!turn->arr[0]->links[i].link->flags.flag)
				{
					turn->arr[0]->links[i].link->flags.flag = TRUE;
					turn_add(turn, turn->arr[0]->links[i].link);
				}
			}
		}
		turn_del(turn);
	}
	get_way(graph, way);
}

void					bfs_algo(t_graph *graph, t_turn *turn, t_way *way)
{
	ssize_t						i;

	turn_add(turn, graph->rooms[0]);
	turn->arr[0]->flags.flag = TRUE;
	while (turn->arr[0])
	{
		i = -1;
		while (++i < turn->arr[0]->iter.i)
			if (!turn->arr[0]->links[i].link->flags.flag &&
					turn->arr[0]->links[i].status && !turn->arr[0]->links[i].condition)
			{
				turn->arr[0]->links[i].link->flags.flag = TRUE;
				if (turn->arr[0]->prev_in_algo[1].link && !turn->arr[0]->prev_in_algo[1].link->flags.flag_of_way &&
					turn->arr[0]->flags.flag_of_way && !turn->arr[0]->links[i].link->flags.flag_of_way)
				{
					turn->arr[0]->links[i].link->flags.flag = FALSE;
					turn->arr[0]->flags.flag = FALSE;
				}
				turn->arr[0]->links[i].link->distance = turn->arr[0]->
						distance + 1;
				turn->arr[0]->links[i].link->prev_in_algo[1].link = turn->arr[0];
				if (turn->arr[0]->links[i].link->flags.flag)
					turn_add(turn, turn->arr[0]->links[i].link);
//				if (turn->arr[0]->prev_in_algo.link && turn->arr[0]->prev_in_algo.link->flags.flags.flag_of_way &&
//					turn->arr[0]->flags.flags.flag_of_way && turn->arr[0]->links[i].link->flags.flags.flag_of_way)
//					turn->arr[0]->links[i].link->flags.flag = FALSE;
			}
		turn_del(turn);
	}
	get_way(graph, way);
}