/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 19:43:23 by ymanilow          #+#    #+#             */
/*   Updated: 2020/01/23 21:56:24 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void				free_data(t_data *data)
{
	hash_free(&data->hash);
	graph_free(&data->graph);
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
	suurballe_algo(&data);
	free_data(&data);
	return(0);
}
