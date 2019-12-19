/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <dbendu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 18:15:50 by dbendu            #+#    #+#             */
/*   Updated: 2019/12/19 21:42:30 by dbendu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vizu.h"

int		vizu_exit(t_wnd *wnd)
{
	mlx_destroy_image(wnd->mlxptr, wnd->imgptr);
	mlx_destroy_window(wnd->mlxptr, wnd->wndptr);
	exit(0);
	return (0);
}

t_wnd	wnd_init(void)
{
	t_wnd	wnd;

	wnd.mlxptr = mlx_init();
	wnd.wndptr = mlx_new_window(wnd.mlxptr, WIDTH, HEIGHT, "lem-in vizualizer");
	wnd.imgptr = mlx_new_image(wnd.mlxptr, WIDTH, HEIGHT);
	wnd.img = mlx_get_data_addr(wnd.imgptr, &wnd.bytes, &wnd.size_line,
								&wnd.endian);
	wnd.bytes /= 8;
	return (wnd);
}


int main(int argc, const char **argv)
{
	// t_wnd	wnd;
	t_data	data;

	if (argc != 2)
		error(2, "Not file", NULL, 0);
	// wnd = wnd_init();
	data = get_map(argv[1]);

	for (size_t i = 0; i < vec_size(data.rooms); ++i)
	{
		printf("%s: %d - %d\n", data.rooms[i].name, data.rooms[i].x, data.rooms[i].y);
	}

	// mlx_put_image_to_window(wnd.mlxptr, wnd.wndptr, wnd.imgptr, 0, 0);

	// mlx_hook(wnd.wndptr, 2, 1L << 0, key_press, &wnd);
	// mlx_hook(wnd.wndptr, 17, 1L << 17, vizu_exit, &wnd);
	// mlx_loop(wnd.mlxptr);
	if (argc && !argv)
		return (0);

	return (0);
}