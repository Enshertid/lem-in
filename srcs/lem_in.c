/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 19:43:23 by ymanilow          #+#    #+#             */
/*   Updated: 2020/01/25 22:07:53 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void				free_data(t_data *data)
{
	hash_free(&data->hash);
	graph_free(&data->graph);
}

int					optimal(t_ways *ways, int ants)
{
	int i;

	i = -1;
	while (++i < ways->iters.col)
		ways->weight += way_weight(&ways->way_ar[i]);
	if (ants <= ways->weight)
		return (1);
	return (0);
}

void 				add_algo_way_to_array(t_ways *ways, t_way *new)
{
	ways->way_ar[ways->iters.col - 1].head = new->head;
	ways->way_ar[ways->iters.col - 1].tail = new->tail;
	new->head = NULL;
	new->tail = NULL;
}

void				algo(t_data *data)
{
	int					i;
	int					j;
	t_way_room *tmp;

	j = 1;
	dijkstra_algo(&data->graph, &data->turn, &data->ways.ways[0].way_ar[0]);
	set_ways_to_the_next_iteration(&data->ways.ways[0], &data->ways.ways[1]);
	while (!optimal(&data->ways.ways[j], data->ants))
	{
		i = -1;
		while (++i < data->ways.ways[j].iters.i)
			wrap_directions(&data->ways.ways[j].way_ar[i]);
		ft_printf("\n");
		i = -1;
		while (++i < data->ways.ways[j].iters.col)
		{
			tmp = data->ways.ways[j].way_ar[i].head;
			while (tmp)
			{
				ft_printf("%s\n", tmp->room->name);
				tmp = tmp->next;
			}
			ft_printf("\n");
		}
		bfs_algo(&data->graph, &data->turn, &data->way_for_algo);
		i = -1;
		while (++i < data->ways.ways[j].iters.i)
			combine_ways_and_cut_common_link(&data->ways.ways[j].way_ar[i], &data->way_for_algo);
		add_algo_way_to_array(&data->ways.ways[j], &data->way_for_algo);
		if (j < data->ways.iters.col)
			set_ways_to_the_next_iteration(&data->ways.ways[j], &data->ways.ways[j + 1]);
		j++;
//		way_clear(&data->way_for_algo);
	}
	//while (!optimal)
	/*{
	 * выключить связи в путях, направленные в конец
	 * нахожу кратчайший путь (вспомогательный)
	 * перекидываю участки смежные с общими ребрами , удаляю ребра
	 * очищаю вспомогательный граф
	 * переношу связи в хранилище новой итерации
	 * }
	 */
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
	way_storage_set(&data.graph, &data.ways);
	data.turn.size= data.graph.iter.col;
	data.turn.arr = turn_create(data.turn.size);
	algo(&data);
	free_data(&data);
	return(0);
}
