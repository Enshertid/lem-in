/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra_modifide.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 16:12:02 by ymanilow          #+#    #+#             */
/*   Updated: 2020/02/12 16:18:02 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void				set_room_to_null(t_room *room)
{
	int						i;

	room->fork[0].prev_in_algo = NULL;
	room->fork[1].prev_in_algo = NULL;
	room->fork[0].distance = MAX_INT;
	room->fork[1].distance = MAX_INT;
	room->fork[0].flag = TRUE;
	room->fork[1].flag = TRUE;
	i = -1;
	while (++i < room->fork[0].iter.col - 1)
	{
		room->fork[0].links[i].status = TRUE;
		room->fork[1].links[i].status = TRUE;
	}
}

void					get_way1(t_graph *graph, t_way *way)
{
	t_fork					*tmp;
	ssize_t					i;

	tmp = &graph->rooms[graph->iter.col - 1]->fork[0];
	while (tmp)
	{
		way_point_add(way, way_point_create(tmp->room));
		tmp = tmp->prev_in_algo;
	}
	i = -1;
	while (++i < graph->iter.col)
		set_room_to_null(graph->rooms[i]);
	graph->rooms[0]->fork[0].distance = 0;
	graph->rooms[0]->fork[1].distance = 0;
	i = -1;
	while (++i < graph->rooms[0]->fork->iter.col - 1)
		graph->rooms[0]->fork->links[i].status = TRUE;
}

void					room_of_way(t_graph *graph, t_turn *turn)
{
	int					i;

	i = -1;
	while (++i < turn->arr[0]->iter.col)
	{
		if (turn->arr[0]->links[i].status && !turn->arr[0]->flag &&
			turn->arr[0]->links[i].link->room != graph->rooms[0] &&
			turn->arr[0]->room != graph->rooms[graph->iter.col - 1])
		{
			if (turn->arr[0]->num_of_way ==
			turn->arr[0]->links[i].link->num_of_way &&
			turn->arr[0]->distance - 1 < turn->arr[0]->links[i].link->distance)
			{
				turn->arr[0]->links[i].link->distance =
				turn->arr[0]->distance - 1;
				turn->arr[0]->links[i].link->prev_in_algo = turn->arr[0];
				turn_add(turn, turn->arr[0]->links[i].link, FALSE);
			}
			else if ( turn->arr[0]->distance + 1 <
				turn->arr[0]->links[i].link->distance)
			{
				turn->arr[0]->links[i].link->distance =
										turn->arr[0]->distance + 1;
				turn->arr[0]->links[i].link->prev_in_algo = turn->arr[0];
				turn_add(turn, turn->arr[0]->links[i].link, FALSE);
			}
		}
	}
}

void					usual_room(t_graph *graph, t_turn *turn)
{
	int					i;

	i = -1;
	while (++i < turn->arr[0]->iter.col)
	{
		if (turn->arr[0]->links[i].status && turn->arr[0]->flag &&
			turn->arr[0]->links[i].link->room != graph->rooms[0] &&
			turn->arr[0]->room != graph->rooms[graph->iter.col - 1])
		{
			if (turn->arr[0]->distance + 1 <
					turn->arr[0]->links[i].link->distance)
			{
				turn->arr[0]->links[i].link->distance =
				turn->arr[0]->distance + 1;
				turn->arr[0]->links[i].link->prev_in_algo = turn->arr[0];
				turn_add(turn, turn->arr[0]->links[i].link, FALSE);
			}
		}
	}
}

void					search_graph_for_way_with_common_links
								(t_graph *graph, t_turn *turn, t_way *way)
{
	turn_add(turn, &graph->rooms[0]->fork[0], FALSE);
	while (turn->arr[0])
	{
		if (turn->arr[0]->in_out)
			room_of_way(graph, turn);
		else
			usual_room(graph, turn);
		turn_del(turn);
	}
	get_way1(graph, way);
}
