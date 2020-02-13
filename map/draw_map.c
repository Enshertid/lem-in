/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 18:05:53 by user              #+#    #+#             */
/*   Updated: 2020/02/05 16:25:39 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
# include "private_map.h"

void			draw_map(t_data *data)
{
	size_t		links_amount;
	size_t		iter;
	t_link		*links;
	int			color;

	ft_memset(data->wnd.graph_img.img, 0,
				HEIGHT * WIDTH * data->wnd.graph_img.bytes);
	links = data->graph.links;
	links_amount = vec_size(links);
	iter = 0;
	while (iter < links_amount)
	{
		if (links->room1->color == __BROWN && links->room2->color == __BROWN)
			color = links->room1->color;
		else
			color = __WHITE;
		draw_line(&data->wnd.graph_img, links->room1->coord,
										links->room2->coord,
										color);
		++links;
		++iter;
	}
}
