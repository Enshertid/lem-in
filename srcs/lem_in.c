/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 19:43:23 by ymanilow          #+#    #+#             */
/*   Updated: 2020/01/24 21:28:45 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void				free_data(t_data *data)
{
	hash_free(&data->hash);
	graph_free(&data->graph);
}


void				algo(t_data *data)
{
	int					i;
	int					j;

	j = 0;
	dijkstra_algo(&data->graph, &data->turn, &data->ways.ways[0].way_ar[0]);
	while (1)
	{
		i = -1;
		while (++i < data->ways.ways[j].iters.col)
			wrap_directions(&data->ways.ways[j].way_ar[i]);
		dijkstra_algo_modifide(&data->graph, &data->turn, &data->way_for_algo);
		i = -1;
		while (++i < data->ways.ways[j].iters.col)
			combine_ways_and_cut_common_link(&data->ways.ways[j].way_ar[i], &data->way_for_algo);
		way_clear(&data->way_for_algo);
		set_ways_to_the_next_iteration(&data->ways.ways[j], &data->ways.ways[j + 1]);
		j++;
		break;
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
	free_data(&data);
	return(0);
}
