/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 17:20:32 by ymanilow          #+#    #+#             */
/*   Updated: 2020/01/16 17:20:32 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void					free_data(t_data *data)
{
	int				i;

	i = -1;
	while (++i <= data->iters.iter)
	{
		free(data->graph[i].links);
		free(data->graph[i].name);
	}
	free(data->graph);
}

void					data_first_set(t_data *data)
{
	ft_memset(data, 0 , sizeof(t_data));
	data->iters.iter = 1;
	data->iters.col = 1;
	data->graph = ft_memalloc(sizeof(t_room) * data->iters.col);
	data->graph[0].name = ft_strnew(0);
}