/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 16:10:59 by ymanilow          #+#    #+#             */
/*   Updated: 2020/02/14 05:40:34 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void				get_days(t_ways *ways, int ants)
{
	int i;

	i = -1;
	while (++i < ways->iters.col)
		ways->weight_sum += way_weight(&ways->way_ar[i]);
	ways->days = (ways->weight_sum + ants) / ways->iters.col;
}

int					optimal(t_data *data, t_ways *new, t_ways *prev, int ants)
{
	data->ways.iters.i++;
	get_days(new, ants);
	if (new->days >= prev->days || ants < new->iters.col ||
	data->ways.iters.i == data->ways.iters.col)
		return (0);
	return (1);
}

void				add_algo_way_to_array(t_ways *ways, t_way *new)
{
	ways->way_ar[ways->iters.col - 1].head = new->head;
	ways->way_ar[ways->iters.col - 1].tail = new->tail;
	new->head = NULL;
	new->tail = NULL;
}

int					first_iteration(t_data *data)
{
	dijkstra_algo(&data->graph, &data->turn, &data->ways.ways[0].way_ar[0]);
	if (data->ways.ways[0].way_ar[0].head->room == data->graph.rooms[0] &&
			data->ways.ways[0].way_ar[0].head->next->room == data->graph.
											rooms[data->graph.iter.col - 1])
		return (0);
	set_ways_to_the_next_iteration(&data->ways.ways[0], &data->ways.ways[1]);
	get_days(&data->ways.ways[0], data->ants);
	return (1);
}

void				print_way(t_way_room *head, char *name)
{
	t_way_room *tmp;
	
	tmp = head;
	ft_printf("%s\n", name);
	while (tmp->next)
	{
		ft_printf("%s ", tmp->room->name);
		tmp = tmp->next;
	}
	ft_printf("%s\n", tmp->room->name);
}

void				algo(t_data *data)
{
	int					i;
	int					j;

	if ((j = first_iteration(data)) != 1)
		return ;
	// print_way(data->ways.ways[0].way_ar[0].head, "first");
	while (1)
	{
		i = -1;
		while (++i < data->ways.ways[j].iters.i)
			wrap_directions(&data->ways.ways[j].way_ar[i], i + 1);
		if (!(search_graph_for_way_with_common_links(&data->graph,
							&data->turn, &data->way_for_algo)))
			break ;
		// print_way(data->way_for_algo.head, "way for algo");
		combine_ways_and_cut_common_link(&data->way_for_algo,
									&data->ways.ways[j], i);
		add_algo_way_to_array(&data->ways.ways[j], &data->way_for_algo);
		if (!optimal(data, &data->ways.ways[j], &data->ways.ways[j - 1],
																data->ants))
			break ;
		set_ways_to_the_next_iteration(&data->ways.ways[j],
												&data->ways.ways[j + 1]);
		j++;
	}
	data->ways.iters.i = j - 1;
}
