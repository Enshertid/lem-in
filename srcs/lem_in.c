/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 19:43:23 by ymanilow          #+#    #+#             */
/*   Updated: 2020/02/13 20:40:18 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void				free_data(t_data *data)
{
	hash_free(&data->hash);
	way_storage_free(&data->ways);
	graph_free(&data->graph);
	turn_free(&data->turn);
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
	while (++i < data->graph.iter.col)
		duplicate_place_for_links(&data->graph.rooms[i]->fork[0],
									&data->graph.rooms[i]->fork[1]);
	way_storage_set(&data->graph, &data->ways);
	data->turn.size = data->graph.iter.col;
	data->turn.arr = turn_create(data->turn.size);
}

int					main(int ac, char **av)
{
	t_data			data;

	if (ac < 0)
		ft_error("haha, ac < 0\n", 1);
	init_data(&data);
	parsing(&data, av);
	init_algo(&data);
	algo(&data);
	free_data(&data);
	return (0);
}
