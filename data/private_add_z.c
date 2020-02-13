/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   private_add_z.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 22:42:42 by user              #+#    #+#             */
/*   Updated: 2020/02/04 22:50:13 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private_data.h"

static size_t		find_best_z_scale(t_coord *coords)
{
	size_t			coords_amount;
	size_t			iter;
	size_t			sum_x;
	size_t			sum_y;

	coords_amount = vec_size(coords);
	sum_x = 0;
	sum_y = 0;
	iter = 0;
	while (iter < coords_amount)
	{
		sum_x += coords[iter].x;
		sum_y += coords[iter].y;
		++iter;
	}
	sum_x /= coords_amount;
	sum_y /= coords_amount;
	return (ft_max(sum_x, sum_y));
}

void				add_z(t_coord *coords)
{
	size_t			rooms;
	size_t			iter;
	int				scale;
	int				z;

	srand(time(NULL));
	scale = find_best_z_scale(coords);
	rooms = vec_size(coords);
	iter = 0;
	while (iter < rooms)
	{
		z = rand() % scale;
		if (z & 1)
			z = -z;
		coords[iter].z = z;
		++iter;
	}
}