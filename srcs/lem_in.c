/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 19:43:23 by ymanilow          #+#    #+#             */
/*   Updated: 2020/02/13 18:03:14 by ymanilow         ###   ########.fr       */
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

void				put_out(t_data *data)
{
	int i;
	t_way_room *tmp;

	i = -1;
	while (++i < data->ways.ways[data->ways.iters.i].iters.i)
	{
		tmp = data->ways.ways[data->ways.iters.i].way_ar[i].head;
		while (tmp)
		{
			ft_printf("%s-",tmp->room->name);
			tmp = tmp->next;
		}
		ft_printf("way lenght = %d\n", data->ways.ways[data->ways.iters.i].way_ar[i].weight);
	}
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
	put_out(&data);
	free_data(&data);
	return (0);
}
