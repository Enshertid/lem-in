/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 22:58:03 by dbendu            #+#    #+#             */
/*   Updated: 2020/02/25 21:54:27 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "mlx.h"

int			main(int argc, char **argv)
{
	t_data data;

	data = data_create(argv);
	draw_map(&data);
	print_map(&data);
	mlx_hook(data.wnd.wndptr, 2, 1L << 0, key_press, &data);
	mlx_hook(data.wnd.wndptr, 4, 1L << 2, mouse_press, &data);
	mlx_hook(data.wnd.wndptr, 5, 1L << 3, mouse_release, &data);
	mlx_hook(data.wnd.wndptr, 6, 1L << 13, mouse_move, &data);
	mlx_loop_hook(data.wnd.mlxptr, animation, &data);
	mlx_loop(data.wnd.mlxptr);
	(void)(argc);
	return (0);
}
