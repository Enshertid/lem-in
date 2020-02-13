/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 21:53:51 by dbendu            #+#    #+#             */
/*   Updated: 2020/02/05 12:39:44 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animation.h"
#include "data.h"

void				shift_ants(t_data *data, int x, int y)
{
	int					iter;
	t_ant				*ant;

	if (data->animation.ants_at_start  == data->animation.ants_amount ||
		data->animation.ants_at_finish == data->animation.ants_amount)
			return ;
	ant = data->animation.ants;
	iter = 0;
	while (iter < data->animation.ants_amount)
	{
		if (ant->start_day > data->animation.cur_day)
			break ;
		if (ant->is_active)
		{
			ant->cur_x += x;
			ant->cur_y += y;
		}
		++iter;
		++ant;
	}
}
