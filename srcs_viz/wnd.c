/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wnd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 21:27:20 by dbendu            #+#    #+#             */
/*   Updated: 2020/02/14 04:54:54 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wnd.h"

static t_img				img_create(void *mlxptr, int widht, int height)
{
	t_img				img;

	img.imgptr = mlx_new_image(mlxptr, widht, height);
	img.img = mlx_get_data_addr(img.imgptr, &img.bytes, &img.size_line,
								&img.endian);
	img.bytes /= 8;
	img.width = widht;
	img.height = height;
	return (img);
}

static t_img				img_create_from_xpm_src(void *mlxptr, char *file)
{
	t_img				img;

	img.imgptr = mlx_xpm_file_to_image(mlxptr, file, &img.width, &img.height);
	img.img = mlx_get_data_addr(img.imgptr, &img.bytes, &img.size_line,
								&img.endian);
	img.bytes /= 8;
	return (img);
}

t_wnd						wnd_create(void)
{
	t_wnd			wnd;

	wnd.mlxptr = mlx_init();
	wnd.wndptr = mlx_new_window(wnd.mlxptr, WIDTH, HEIGHT, "lemin");
	wnd.graph_img = img_create(wnd.mlxptr, WIDTH, HEIGHT);
	wnd.ant_img = img_create_from_xpm_src(wnd.mlxptr,
												"srcs_viz/images/ant.xpm");
	wnd.start_circle_img = img_create_from_xpm_src(wnd.mlxptr,
												"srcs_viz/images/start.xpm");
	wnd.end_circle_img = img_create_from_xpm_src(wnd.mlxptr,
												"srcs_viz/images/end.xpm");
	wnd.pentagon_img = img_create_from_xpm_src(wnd.mlxptr,
												"srcs_viz/images/pentagon.xpm");
	return (wnd);
}

void						wnd_destroy(t_wnd *wnd)
{
	mlx_destroy_image(wnd->mlxptr, wnd->graph_img.imgptr);
	mlx_destroy_image(wnd->mlxptr, wnd->ant_img.imgptr);
	mlx_destroy_image(wnd->mlxptr, wnd->start_circle_img.imgptr);
	mlx_destroy_image(wnd->mlxptr, wnd->end_circle_img.imgptr);
	mlx_destroy_image(wnd->mlxptr, wnd->pentagon_img.imgptr);
	mlx_destroy_window(wnd->mlxptr, wnd->wndptr);
}
