/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <dbendu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 21:48:18 by dbendu            #+#    #+#             */
/*   Updated: 2020/02/14 03:18:56 by dbendu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static void		put_ant(t_wnd *wnd, t_img *img, int x, int y)
{
	mlx_put_image_to_window(wnd->mlxptr, wnd->wndptr, img->imgptr,
							x - (img->width >> 1), y - (img->height >> 1));
}

static void		show_rooms_names(void *mlxptr, void *wndptr,
										t_room *rooms)
{
	size_t			rooms_amount;
	size_t			iter;

	rooms_amount = vec_size(rooms);
	iter = 0;
	while (iter < rooms_amount)
	{
		mlx_string_put(mlxptr, wndptr, rooms->coord.x, rooms->coord.y + 25,
						__GREEN, rooms->name);
		++rooms;
		++iter;
	}
}

static void		show_ants_on_tails(t_data *data)
{
	char			*str;

	if (data->animation.ants_at_start)
	{
		put_ant(&data->wnd, &data->wnd.ant_img,
					data->graph.rooms[0].coord.x, data->graph.rooms[0].coord.y);
		str = ft_itoa(data->animation.ants_at_start, NULL, 10, 0);
		mlx_string_put(data->wnd.mlxptr, data->wnd.wndptr,
	data->graph.rooms[0].coord.x + 15, data->graph.rooms[0].coord.y + 15,
		__RED, str);
		free(str);
	}
	if (data->animation.ants_at_finish)
	{
		put_ant(&data->wnd, &data->wnd.ant_img,
					data->graph.rooms[1].coord.x, data->graph.rooms[1].coord.y);
		str = ft_itoa(data->animation.ants_at_finish, NULL, 10, 0);
		mlx_string_put(data->wnd.mlxptr, data->wnd.wndptr,
	data->graph.rooms[1].coord.x + 15, data->graph.rooms[1].coord.y + 15,
		__RED, str);
		free(str);
	}
}

static void		mark_visited_rooms(t_data *data)
{
	size_t		iter;
	size_t		rooms_amount;
	t_room		**rooms;

	rooms = data->animation.visited_rooms;
	rooms_amount = vec_size(rooms);
	iter = 0;
	while (iter < rooms_amount)
	{
		mlx_put_image_to_window(data->wnd.mlxptr, data->wnd.wndptr,
					data->wnd.pentagon_img.imgptr, rooms[iter]->coord.x - 15,
													rooms[iter]->coord.y - 15);
		++iter;
	}
}

void			put_info(t_data *data)
{
	mlx_put_image_to_window(data->wnd.mlxptr, data->wnd.wndptr,
				data->wnd.start_circle_img.imgptr,
		data->graph.rooms[0].coord.x - 15, data->graph.rooms[0].coord.y - 15);
	mlx_put_image_to_window(data->wnd.mlxptr, data->wnd.wndptr,
				data->wnd.end_circle_img.imgptr,
		data->graph.rooms[1].coord.x - 15, data->graph.rooms[1].coord.y - 15);
	show_ants_on_tails(data);
	if (data->appearance.show_rooms_names)
		show_rooms_names(data->wnd.mlxptr, data->wnd.wndptr, data->graph.rooms);
	if (data->flags & FLAG_MARK_WAYS)
		mark_visited_rooms(data);
}
