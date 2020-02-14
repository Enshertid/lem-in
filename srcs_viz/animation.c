/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 21:51:17 by dbendu            #+#    #+#             */
/*   Updated: 2020/02/05 16:45:23 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "libft.h"

int			animation(t_data *data)
{
	if (!data->animation.is_animation_active)
		return (0);
	if (data->animation.ants_at_finish == data->animation.ants_amount)
	{
		data->animation.is_animation_active = FALSE;
		return (0);
	}
	if (!data->animation.cur_tick)
		setup_ants_moving(data);
	mlx_put_image_to_window(data->wnd.mlxptr, data->wnd.wndptr,
							data->wnd.graph_img.imgptr, 0, 0);
	put_info(data);
	move_ants(data);
	print_ants(data);
	++data->animation.cur_tick;
	if (data->animation.cur_tick == data->animation.ticks)
	{
		data->animation.cur_tick = 0;
		++data->animation.cur_day;
	}
	usleep(10000);
	return (0);
}
