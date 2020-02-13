/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 22:06:56 by dbendu            #+#    #+#             */
/*   Updated: 2020/02/04 18:12:26 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_defines.h"
#include "lemin.h"
#include "data.h"

static void			key_press3(int button, t_data *data)
{
	if (button == W)
		data->appearance.angles.x_angle += 5;
	else if (button == S)
		data->appearance.angles.x_angle -= 5;
	else if (button == D)
		data->appearance.angles.y_angle -= 5;
	else if (button == A)
		data->appearance.angles.y_angle += 5;
	else if (button == E)
		data->appearance.angles.z_angle -= 5;
	else if (button == Q)
		data->appearance.angles.z_angle += 5;
	if (abs(data->appearance.angles.x_angle) == 360)
		data->appearance.angles.x_angle = 0;
	if (abs(data->appearance.angles.y_angle) == 360)
		data->appearance.angles.y_angle = 0;
	if (abs(data->appearance.angles.z_angle) == 360)
		data->appearance.angles.z_angle = 0;
}

static void			key_press2(int button, t_data *data)
{
	int				iter;
	t_ant			*ant;

	if (button == R)
	{
		data->animation.is_animation_active = FALSE;
		ant = data->animation.ants;
		iter = 0;
		while (iter < data->animation.ants_amount)
		{
			ant->cur_room = 0;
			ant->is_active = FALSE;
			++ant;
			++iter;
		}
		data->animation.cur_tick = 0;
		data->animation.cur_day = 1;
		data->animation.ants_at_finish = 0;
		data->animation.ants_at_start = data->animation.ants_amount;
	}
}

static void			key_press1(int button, t_data *data)
{
	if (button == I)
		data->appearance.show_rooms_names = !data->appearance.show_rooms_names;
	else if (button == PLUS)
		data->camera.z += 3;
	else if (button == MINUS)
		data->camera.z -= 3;
	else if (button == SPACE)
	{
		data->appearance.angles.x_angle = 0;
		data->appearance.angles.y_angle = 0;
		data->appearance.angles.z_angle = 0;
		data->camera.z = 0;
	}
	else
		button == R ? key_press2(button, data) : key_press3(button, data);
	if (button != ENTER && button != I && button != R)
		rotate_map(data);
}

int					key_press(int button, t_data *data)
{
	if (button == ESC)
		lemin_exit(data);
	else if (button == ENTER)
		data->animation.is_animation_active =
		!data->animation.is_animation_active;
	else if (button == UP)
		shift_map(data, 0, -10);
	else if (button == DOWN)
		shift_map(data, 0, 10);
	else if (button == LEFT)
		shift_map(data, -10, 0);
	else if (button == RIGHT)
		shift_map(data, 10, 0);
	else
		key_press1(button, data);
	draw_map(data);
	print_map(data);
	return (0);
}
