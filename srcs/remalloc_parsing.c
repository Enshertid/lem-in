/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remalloc_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 15:12:38 by ymanilow          #+#    #+#             */
/*   Updated: 2020/01/23 22:13:47 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void						set_hash_to_null(t_hash_table *hash)
{
	int					i;
	int					j;

	i = -1;
	while(++i < hash->size)
	{
		if(hash->hash_table[i].iter.col)
		{
			j = -1;
			while(++j < hash->hash_table[i].iter.i)
				hash->hash_table[i].rooms[j] = NULL;
		}
	}
}

void						set_relink(t_hash_table *hash, t_graph *graph, int size)
{
	int					i;
	int					j;

	i = -1;
	while(++i < size)
	{
		j = 0;
		if (hash->hash_table[graph->rooms[i]->hash_index].iter.i)
		{
			while (j < hash->hash_table[graph->rooms[i]->hash_index].iter.i &&
					hash->hash_table[graph->rooms[i]->hash_index].rooms[j])
				j++;
			hash->hash_table[graph->rooms[i]->hash_index].rooms[j] = graph->rooms[i];
		}
	}
}

void						relink_hash_table(t_hash_table *hash, t_graph *graph, int size)
{
	set_hash_to_null(hash);
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
