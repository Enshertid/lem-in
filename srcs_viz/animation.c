/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 21:51:17 by dbendu            #+#    #+#             */
/*   Updated: 2020/02/26 16:18:19 by ymanilow         ###   ########.fr       */
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
	setup_ants_moving(data);
	for (int i = 0; i < data->animation.ticks; ++i) {
		mlx_put_image_to_window(data->wnd.mlxptr, data->wnd.wndptr,
								data->wnd.graph_img.imgptr, 0, 0);
		put_info(data);
		move_ants(data);
		print_ants(data);
		mlx_do_sync(data->wnd.mlxptr);
	}
	++data->animation.cur_day;
	usleep(500);
	return (0);
}
