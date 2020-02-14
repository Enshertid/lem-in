/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 19:43:23 by ymanilow          #+#    #+#             */
/*   Updated: 2020/02/14 04:57:28 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void				free_data(t_data *data)
{
	hash_free(&data->hash);
	way_storage_free(&data->ways);
	graph_free(&data->graph);
	turn_free(&data->turn);
	buf_destroy();
}

void				init_data(t_data *data)
{
	ft_memset(data, 0, sizeof(t_data));
	data->hash.size = HASH_SIZE;
	data->hash.hash_table = hash_array_create(data->hash.size);
	data->graph = set_graph();
}

void				init_algo(t_data *data)
{
	int				i;

	i = -1;
	if (data->graph.rooms[data->graph.iter.col - 1]->fork[0].iter.col == 0)
		ft_error("have no links at end\n", 10);
	if (data->graph.rooms[0]->fork[0].iter.col == 0)
		ft_error("have no links at start\n", 10);
	while (++i < data->graph.iter.col)
		duplicate_place_for_links(&data->graph.rooms[i]->fork[0],
									&data->graph.rooms[i]->fork[1]);
	way_storage_set(&data->graph, &data->ways);
	data->turn.size = data->graph.iter.col;
	data->turn.arr = turn_create(data->turn.size);
}

int					main(void)
{
	t_data			data;

	buf_init(1, 0);
	init_data(&data);
	parsing(&data);
	init_algo(&data);
	algo(&data);
	print(&data.ways.ways[data.ways.iters.i], data.ants);
	free_data(&data);
	return (0);
}
