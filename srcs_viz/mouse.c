/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 23:06:51 by dbendu            #+#    #+#             */
/*   Updated: 2020/02/25 21:44:34 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_defines.h"
#include "lemin.h"
#include "libft.h"
#include "data.h"

int					mouse_press(int key, int x, int y, t_data *data)
{
	if (x < 0 || y < 0 || x >= MAX_X || y > MAX_Y)
		return (0);
	if (key == LEFT_BUTTON)
	{
		data->mouse.is_left_button_active = TRUE;
		data->mouse.x = x;
		data->mouse.y = y;
	}
	else if (key == WHEEL_UP)
		data->camera.z += 3;
	else if (key == WHEEL_DOWN)
		data->camera.z -= 3;
	if (key == WHEEL_UP || key == WHEEL_DOWN)
		rotate_map(data);
	draw_map(data);
	print_map(data);
	return (0);
}

int					mouse_move(int x, int y, t_data *data)
{
	if (data->mouse.is_left_button_active)
	{
		shift_map(data, x - data->mouse.x,
					y - data->mouse.y);
		data->mouse.x = x;
		data->mouse.y = y;
		draw_map(data);
		print_map(data);
	}
	return (0);
}

int					mouse_release(int button, int x, int y, t_data *data)
{
	if (button == LEFT_BUTTON)
		data->mouse.is_left_button_active = FALSE;
	(void)(x);
	(void)(y);
	return (0);
}
