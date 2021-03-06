/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 16:10:59 by ymanilow          #+#    #+#             */
/*   Updated: 2020/03/15 15:51:03 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int				eval_days(t_way *ways, int ways_amount, int ants)
{
	int				days;
	int				iter;

	days = 0;
	while (ants > 0)
	{
		++days;
		iter = 0;
		while (iter < ways_amount)
		{
			if (days / ways[iter].weight)
				--ants;
			++iter;
		}
	}
	return (days);
}

int						optimal(t_data *data, t_ways *new, int ants)
{
	int		i;

	i = -1;
	while (++i < new->iters.col)
		new->weight_sum += way_weight(&new->way_ar[i]);
	data->ways.iters.i++;
	new->days = eval_days(new->way_ar, new->iters.col, ants);
	if (ants < new->iters.col ||
	data->ways.iters.i == data->ways.iters.col)
		return (0);
	return (1);
}

void					add_algo_way_to_array(t_ways *ways, t_way *new)
{
	ways->way_ar[ways->iters.col - 1].head = new->head;
	ways->way_ar[ways->iters.col - 1].tail = new->tail;
	new->head = NULL;
	new->tail = NULL;
}

static int				first_iteration(t_data *data)
{
	dijkstra_algo(&data->graph, &data->turn, &data->ways.ways[0].way_ar[0]);
	if (data->ways.ways[0].way_ar[0].head->room
				== data->graph.rooms[data->graph.iter.col - 1])
		ft_error("start & end are not connected", 500);
	if (data->ways.ways[0].way_ar[0].head->room == data->graph.rooms[0] &&
			data->ways.ways[0].way_ar[0].head->next->room == data->graph.
											rooms[data->graph.iter.col - 1])
	{
		data->ways.ways[0].days = 1;
		return (0);
	}
	set_ways_to_the_next_iteration(&data->ways.ways[0], &data->ways.ways[1]);
	data->ways.ways[0].weight_sum = way_weight(&data->ways.ways[0].way_ar[0]);
	data->ways.ways[0].days = eval_days(data->ways.ways[0].way_ar, 1,
															data->ants);
	data->ways.ways[0].flag = TRUE;
	return (1);
}

int						algo(t_data *data)
{
	int					i;
	int					j;

	if ((j = first_iteration(data)) != 1)
		return (j);
	while (1)
	{
		i = -1;
		while (++i < data->ways.ways[j].iters.i)
			wrap_directions(&data->ways.ways[j].way_ar[i], i + 1);
		if (!(search_graph_for_way_with_common_links(&data->graph,
							&data->turn, &data->way_for_algo)))
			break ;
		combine_ways_and_cut_common_link(&data->way_for_algo,
									&data->ways.ways[j], i);
		add_algo_way_to_array(&data->ways.ways[j], &data->way_for_algo);
		if (!optimal(data, &data->ways.ways[j], data->ants))
			break ;
		set_ways_to_the_next_iteration(&data->ways.ways[j],
												&data->ways.ways[j + 1]);
		j++;
	}
	data->ways.iters.i = j - 1;
	return (check_optimal(&data->ways));
}
