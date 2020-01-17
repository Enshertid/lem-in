/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 19:09:22 by ymanilow          #+#    #+#             */
/*   Updated: 2020/01/17 16:06:50 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"


void					make_copy_graph(t_data *data)
{
	int					i;
	int					j;

	data->copy = ft_memalloc(sizeof(t_room) * data->iters.iter);
	i = -1;
	while (++i < data->iters.iter + 1)
	{
		ft_memcpy(&data->copy[i],&data->graph[i], sizeof(t_room));
		data->copy[i].iters.col = data->graph[i].iters.iter;
		data->copy[i].links = ft_memalloc(sizeof(t_room) * data->copy->iters.col);
	}
	i = -1;
	while(++i < data->iters.iter + 1)
	{
		data->copy[i].links = ft_memalloc(sizeof(t_room*) *data->copy[i].iters.col);
		data->copy[i].iters.iter = -1;
		while(++data->copy[i].iters.iter < data->copy[i].iters.col)
		{
			j = -1;
			while(++j < data->iters.iter + 1)
				if (ft_strequ(data->copy[j].name, data->graph[i].links[data->copy[i].iters.iter]->name))
					data->copy[i].links[data->copy[i].iters.iter] = &data->copy[j];
		}
	}
}

void					cut_the_ways(t_data *data)
{
	int				i;
	int				j;


	i = data->iters.iter;
	while(i != 0)
	{
		j = -1;
		while(++j < data->copy[i].iters.col)
		{
			if (data->copy[i].links[j]->num_on_the_search == data->copy[i].num_on_the_search - 1)
			{
				i = data->copy[i].links[j]->num_on_array;
			}
		}
	}
}

void					suurballe_algo(t_data *data)
{

//	make_copy_graph(data);
	dijkstra_list(data);
//	cut_the_ways(data);
//	bfs_array(data);
}


int						main(int ac, char **av)
{
	t_data			data;
	if (ac < 0)
		ft_error("ahahahah\n", 100);
	data_first_set(&data);
	ft_parsing(av, &data);
	if (!data.graph[0].link_presence ||
		!data.graph[data.iters.iter].link_presence)
		ft_error("have no links\n", 1000);
	suurballe_algo(&data);
	free_data(&data);
	ft_printf("all is fine\n");
	return (0);
}