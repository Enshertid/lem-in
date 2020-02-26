/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 19:43:23 by ymanilow          #+#    #+#             */
/*   Updated: 2020/02/26 16:14:26 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void				free_data(t_data *data)
{
	t_way_room *tmp;
	t_way_room *tmp1;

	hash_free(&data->hash);
	way_storage_free(&data->ways);
	if (data->way_for_algo.head)
	{
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
	graph_free(&data->graph);
	turn_free(&data->turn);
	buf_destroy();
}

static void				init_algo(t_data *data)
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

static void				init_data(t_data *data, char **av)
{
	buf_init(1, 10000);
	ft_memset(data, 0, sizeof(t_data));
	data->hash.size = HASH_SIZE;
	data->hash.hash_table = hash_array_create(data->hash.size);
	data->graph = set_graph();
	// data->pars.fd = open(av[1], O_RDONLY);
	(void)av;
	data->pars.fd = 0;
	parsing(data);
	init_algo(data);
}

int						main(int ac, char **av)
{
	t_data			data;

	(void)ac;
	init_data(&data, av);
	algo(&data);
	print(&data.ways.ways[data.ways.iters.i], data.ants);
	free_data(&data);
	(void)av;
	return (0);
}
