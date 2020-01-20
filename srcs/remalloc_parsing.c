/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remalloc_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 15:12:38 by ymanilow          #+#    #+#             */
/*   Updated: 2020/01/20 13:17:02 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void						set_hash_to_null(t_hash_table *hash, t_graph *graph, int size)
{
	int					i;
	t_hash				*tmp;

	i = -1;
	while(++i < size)
	{
		if (hash->hash_table[graph->rooms[i]->hash_index].room)
			hash->hash_table[graph->rooms[i]->hash_index].room = NULL;
		else
		{
			if (hash->hash_table[graph->rooms[i]->hash_index].next)
			{
				tmp = hash->hash_table[graph->rooms[i]->hash_index].next;
				while (tmp)
				{
					tmp->room = NULL;
					tmp = tmp->next;
				}
			}
		}
	}
}

void						set_relink(t_hash_table *hash, t_graph *graph, int size)
{
	int					i;
	t_hash				*tmp;

	i = -1;
	while(++i < size)
	{
		if (!hash->hash_table[graph->rooms[i]->hash_index].room)
			hash->hash_table[graph->rooms[i]->hash_index].room =
					graph->rooms[i];
		else if (hash->hash_table[graph->rooms[i]->hash_index].next)
		{
			tmp = hash->hash_table[graph->rooms[i]->hash_index].next;
			while (tmp && tmp->room)
				tmp = tmp->next;
			if (tmp)
				tmp->room = graph->rooms[i];
		}
	}
}

void						relink_hash_table(t_hash_table *hash, t_graph *graph, int size)
{
	set_hash_to_null(hash, graph, size);
	set_relink(hash, graph, size);
}

void					final_remalloc_graph(t_data *data)
{
	t_room					**tmp;
	int						i;

	data->graph.iter.col = data->graph.iter.i;
	data->graph.iter.i = 0;
	tmp = ft_memalloc(sizeof(t_room*) * data->graph.iter.col);
	i = -1;
	while(++i < data->graph.iter.col)
		tmp[i] = data->graph.rooms[i];
	free(data->graph.rooms);
	data->graph.rooms = tmp;
	relink_hash_table(&data->hash, &data->graph, data->graph.iter.col);
}

void					remalloc_of_graph(t_data *data)
{
	t_room					**tmp;
	int						i;

	data->graph.iter.col *= 3;
	tmp = ft_memalloc(sizeof(t_room*) * data->graph.iter.col);
	i = -1;
	while(++i < data->graph.iter.i)
		tmp[i] = data->graph.rooms[i];
	free(data->graph.rooms);
	data->graph.rooms = tmp;
	relink_hash_table(&data->hash, &data->graph, data->graph.iter.i);
}
