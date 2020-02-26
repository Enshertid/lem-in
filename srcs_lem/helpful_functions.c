/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpful_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 16:43:53 by ymanilow          #+#    #+#             */
/*   Updated: 2020/02/26 16:47:06 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_ant				*create_ants(int ants_amount)
{
	t_ant			*ants;
	int				iter;

	ants = malloc(sizeof(t_ant) * ants_amount);
	if (!ants)
		exit(1);
	iter = 0;
	while (iter < ants_amount)
	{
		ants[iter].is_active = TRUE;
		++iter;
	}
	return (ants);
}

int					check_optimal(t_storage_w *ways)
{
	int i;
	int j;
	int min;

	min = MAX_INT;
	i = -1;
	j = ways->iters.i;
	while (++i <= ways->iters.i)
	{
		if (min >= ways->ways[i].days)
		{
			min = ways->ways[i].days;
			j = i;
		}
	}
	return (j);
}

void				sort_ways_arr(t_way *ways_arr, int j)
{
	int				i;
	t_way			temp;

	j--;
	while (j > 0)
	{
		i = 0;
		while (i < j)
		{
			if (ways_arr[i].weight > ways_arr[j].weight)
			{
				temp = ways_arr[i];
				ways_arr[i] = ways_arr[j];
				ways_arr[j] = temp;
			}
			++i;
		}
		--j;
	}
}
