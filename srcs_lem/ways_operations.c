/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ways_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 17:25:00 by ymanilow          #+#    #+#             */
/*   Updated: 2020/02/13 21:02:34 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ways.h"

void				get_copy_of_way(t_way *prev, t_way *new)
{
	t_way_room		*tmp_prev;
	
	tmp_prev = prev->tail;
	while (tmp_prev)
	{
		way_point_add(new, way_point_create(tmp_prev->room));
		tmp_prev = tmp_prev->prev;
	}
}
