/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 21:53:42 by dbendu            #+#    #+#             */
/*   Updated: 2020/02/05 12:38:41 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animation.h"
#include "data.h"

void			move_ants(t_data *data)
{
	int			iter;
	t_ant		*ant;

	ant = data->animation.ants;
	iter = 0;
	while (iter < data->animation.ants_amount)
	{
		if (ant->start_day > data->animation.cur_day)
			break ;
		if (ant->is_active)
		{
			ant->cur_x += ant->x_offset;
			ant->cur_y += ant->y_offset;
		}
		++ant;
		++iter;
	}
}
