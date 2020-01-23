/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ways.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 23:04:20 by ymanilow          #+#    #+#             */
/*   Updated: 2020/01/23 22:35:48 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ways.h"

void						ways_array_malloc(t_ways *ways)
{
	t_way					**ways_array;
	int						i;

	if (!ways->iters.col)
		ways->iters.col = 5;
	else
		ways->iters.col *= 5;
	ways_array = ft_memalloc(sizeof(t_way*) * ways->iters.col);
	if (ways->iters.col != 5)
	{
		i = -1;
		while (++i < ways->iters.i)
			ways_array[i] = ways->way_ar[i];
		free(ways->way_ar);
	}
	ways->way_ar = ways_array;
}

t_way						*point_of_way_create(t_room *room)
{
	t_way					*point;

	point = ft_memalloc(sizeof(t_way));
	point->room = room;
	point->next = NULL;
	return (point);
}