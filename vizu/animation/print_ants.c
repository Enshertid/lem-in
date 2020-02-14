/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <dbendu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 21:53:40 by dbendu            #+#    #+#             */
/*   Updated: 2020/02/14 01:30:08 by dbendu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animation.h"
#include "data.h"

void			print_ants(t_data *data)
{
	int			iter;
	t_ant		*ant;

	if (data->animation.ants_at_start == data->animation.ants_amount ||
		data->animation.ants_at_finish == data->animation.ants_amount)
		return ;
	ant = data->animation.ants;
	iter = 0;
	while (iter < data->animation.ants_amount)
	{
		if (ant->start_day > data->animation.cur_day)
			break ;
		if (ant->is_active)
			mlx_put_image_to_window(data->wnd.mlxptr, data->wnd.wndptr,
				data->wnd.ant_img.imgptr, ant->cur_x - 5, ant->cur_y - 8);
		++ant;
		++iter;
	}
}
