/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remalloc_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 15:12:38 by ymanilow          #+#    #+#             */
/*   Updated: 2020/01/18 18:53:02 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void					remalloc_graph(t_data *data)
{
	t_room					*tmp;
	int						i;

	data->graph.iter.col = data->graph.iter.i;
	data->graph.iter.i = 0;
	tmp = ft_memalloc(sizeof(t_room) * data->graph.iter.col);
	i = -1;
	tmp = ft_memcpy(tmp, data->graph.rooms, sizeof(t_room) * data->graph.iter.col);
	while(++i < data->graph.iter.col)
		tmp[i].name = data->graph.rooms[i].name;
	free(data->graph.rooms);
	data->graph.rooms = tmp;
}

void					remalloc_of_graph(t_data *data)
{
	t_room					*tmp;
	int						i;

	data->graph.iter.col *= 3;
	tmp = ft_memalloc(sizeof(t_room) * data->graph.iter.col);
	i = -1;
	tmp = ft_memcpy(tmp, data->graph.rooms, sizeof(t_room) * data->graph.iter.i);
	while(++i < data->graph.iter.i)
		tmp[i].name = data->graph.rooms[i].name;
	free(data->graph.rooms);
	data->graph.rooms = tmp;
}
