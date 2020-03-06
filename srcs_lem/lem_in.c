/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 19:43:23 by ymanilow          #+#    #+#             */
/*   Updated: 2020/03/06 14:34:11 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void				free_way_for_algo(t_data *data)
{
	t_way_room *tmp;
	t_way_room *tmp1;

	tmp1 = data->way_for_algo.head;
	tmp = data->way_for_algo.head->next;
	while (tmp)
	{
		free(tmp1);
		tmp1 = tmp;
		tmp = tmp->next;
	}
	free(tmp1);
}

static void				free_data(t_data *data)
{
	hash_free(&data->hash);
	way_storage_free(&data->ways);
	if (data->way_for_algo.head)
		free_way_for_algo(data);
	graph_free(&data->graph);
	turn_free(&data->turn);
	buf_destroy();
}

static void				init_algo(t_data *data)
{
	int				i;

	i = -1;
	if (data->graph.rooms[data->graph.iter.col - 1]->fork[0].iter.col == 0)
		ft_error("have no links at end", 10);
	if (data->graph.rooms[0]->fork[0].iter.col == 0)
		ft_error("have no links at start", 10);
	while (++i < data->graph.iter.col)
		duplicate_place_for_links(&data->graph.rooms[i]->fork[0],
									&data->graph.rooms[i]->fork[1]);
	way_storage_set(&data->graph, &data->ways);
	data->turn.size = data->graph.iter.col;
	data->turn.arr = turn_create(data->turn.size);
}

static void				init_data(t_data *data)
{
	buf_init(1, 10000);
	ft_memset(data, 0, sizeof(t_data));
	data->hash.size = HASH_SIZE;
	data->hash.hash_table = hash_array_create(data->hash.size);
	data->graph = set_graph();
	parsing(data);
	init_algo(data);
}

int						main(void)
{
	t_data			data;

	init_data(&data);
	algo(&data);
	print(&data.ways.ways[data.ways.iters.i], data.ants);
	free_data(&data);
	return (0);
}
