/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 21:47:30 by dbendu            #+#    #+#             */
/*   Updated: 2020/02/05 12:42:49 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static void		set_angles(t_angles *angles)
{
	angles->cosx = cos(angles->x_angle * 3.14 / 180);
	angles->cosy = cos(angles->y_angle * 3.14 / 180);
	angles->cosz = cos(angles->z_angle * 3.14 / 180);
	angles->sinx = sin(angles->x_angle * 3.14 / 180);
	angles->siny = sin(angles->y_angle * 3.14 / 180);
	angles->sinz = sin(angles->z_angle * 3.14 / 180);
}

static void		rotate_x(t_data *data)
{
	size_t		iter;
	size_t		rooms_amount;
	int			y;
	int			z;

	rooms_amount = vec_size(data->graph.rooms);
	iter = 0;
	while (iter < rooms_amount)
	{
		y = data->graph.basic_coords[iter].y;
		if (y + data->camera.y > data->graph.center.y)
			y += data->camera.z;
		else
			y -= data->camera.z;
		z = data->graph.basic_coords[iter].z;
		if (z > 0)
			z += data->camera.z;
		else
			z -= data->camera.z;
		data->graph.rooms[iter].coord.y = y * data->appearance.angles.cosx + z * data->appearance.angles.sinx;
		data->graph.rooms[iter].coord.z = -y * data->appearance.angles.sinx + z * data->appearance.angles.cosx;
		++iter;
	}
}

static void		rotate_y(t_data *data)
{
	size_t		iter;
	size_t		rooms_amount;
	int			x;
	int			z;

	rooms_amount = vec_size(data->graph.rooms);
	iter = 0;
	while (iter < rooms_amount)
	{
		x = data->graph.basic_coords[iter].x;
		if (x + data->camera.x > data->graph.center.x)
			x += data->camera.z;
		else
			x -= data->camera.z;
		z = data->graph.rooms[iter].coord.z;
		data->graph.rooms[iter].coord.x =  x * data->appearance.angles.cosy + z * data->appearance.angles.siny;
		data->graph.rooms[iter].coord.z = -x * data->appearance.angles.siny + z * data->appearance.angles.cosy;
		++iter;
	}
}

static void		rotate_z(t_data *data)
{
	size_t		iter;
	size_t		rooms_amount;
	int			x;
	int			y;

	rooms_amount = vec_size(data->graph.rooms);
	iter = 0;
	while (iter < rooms_amount)
	{
		x = data->graph.rooms[iter].coord.x;
		y = data->graph.rooms[iter].coord.y;
		data->graph.rooms[iter].coord.x = x * data->appearance.angles.cosz - y * data->appearance.angles.sinz;
		data->graph.rooms[iter].coord.y = x * data->appearance.angles.sinz + y * data->appearance.angles.cosz;
		data->graph.rooms[iter].coord.x += data->camera.x;
		data->graph.rooms[iter].coord.y += data->camera.y;
		++iter;
	}
}

void			rotate_map(t_data *data)
{
	set_angles(&data->appearance.angles);
	rotate_x(data);
	rotate_y(data);
	rotate_z(data);
	rotate_ants(data);
}
