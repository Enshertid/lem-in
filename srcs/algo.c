/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 16:10:59 by ymanilow          #+#    #+#             */
/*   Updated: 2020/02/13 14:20:23 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int					optimal(t_ways *ways, int ants)
{
	(void)ways;
	(void)ants;
	return (0);
	// int i;
//
	// i = -1;
	// while (++i < ways->iters.col)
		// ways->weight += way_weight(&ways->way_ar[i]);
	// if (ants <= ways->weight)
		// return (1);
	// return (0);
}

void				add_algo_way_to_array(t_ways *ways, t_way *new)
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

	j = 1;
	dijkstra_algo(&data->graph, &data->turn, &data->ways.ways[0].way_ar[0]);
	set_ways_to_the_next_iteration(&data->ways.ways[0], &data->ways.ways[j]);
	while (!optimal(&data->ways.ways[j], data->ants))
	{
		i = -1;
		while (++i < data->ways.ways[j].iters.i)
			wrap_directions(&data->ways.ways[j].way_ar[i], i + 1);
		if (!(search_graph_for_way_with_common_links(&data->graph,
							&data->turn, &data->way_for_algo)))
			break ;
		combine_ways_and_cut_common_link(&data->way_for_algo,
									&data->ways.ways[j]);
		add_algo_way_to_array(&data->ways.ways[j], &data->way_for_algo);
		set_ways_to_the_next_iteration(&data->ways.ways[j],
												&data->ways.ways[j + 1]);
		j++;
	}
	// i = -1;
	// while (++i < data->ways.iters.col)
		// put_out_array_of_ways(data->ways.ways[i], i);
}
