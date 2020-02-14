/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 21:39:52 by dbendu            #+#    #+#             */
/*   Updated: 2020/02/05 12:42:23 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void					print_map(t_data *data)
{
	mlx_put_image_to_window(data->wnd.mlxptr, data->wnd.wndptr,
							data->wnd.graph_img.imgptr, 0, 0);
	put_info(data);
	print_ants(data);
}
