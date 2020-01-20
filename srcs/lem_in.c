/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 19:43:23 by ymanilow          #+#    #+#             */
/*   Updated: 2020/01/20 22:54:07 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void				free_data(t_data *data)
{
	hash_free(&data->hash);
	graph_free(&data->graph);
}

void				dijkstra_algo(t_turn *turn, t_graph *graph)
{
	ssize_t						i;

	turn_add(turn, graph->rooms[0]);
	while(turn->arr[0])
	{
		i = -1;
		while(++i < turn->arr[0]->iter.i)
		{
			if (turn->arr[0]->links[i].status &&
			turn->arr[0]->distance + 1 < turn->arr[0]->links[i].link->distance)
			{
				turn->arr[0]->links[i].link->prev_in_algo.link
				= turn->arr[0];
				turn->arr[0]->links[i].link->distance = turn->arr[0]->distance + 1;
				if (!turn->arr[0]->links[i].link->flag)
				{
					turn->arr[0]->links[i].link->flag = 1;
					turn_add(turn, turn->arr[0]->links[i].link);
				}
			}
		}
		turn_del(turn);
	}
}

void 				suurballe_algo(t_data *data)
{
	data->turn.size = data->graph.iter.col;
	data->turn.arr = turn_create(data->turn.size);
	dijkstra_algo(&data->turn, &data->graph);
	get_way(&data->graph, &data->ways)
}

int					main(int ac, char **av)
{
	t_data				data;
	
	if (ac < 0)
		ft_error("haha, ac < 0\n", 1);
	ft_memset(&data, 0, sizeof(t_data));
	data.hash.hash_table = hash_array_create(HASH_SIZE);
	data.hash.size = HASH_SIZE;
	data.graph = set_graph();
	parsing(&data, av);
	suurballe_algo(&data);
	free_data(&data);
	return(0);
}
