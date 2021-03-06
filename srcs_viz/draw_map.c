/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 18:05:53 by user              #+#    #+#             */
/*   Updated: 2020/02/26 18:07:05 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "private_map.h"

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
		if (links->room1->color == __BROWN || links->room2->color == __BROWN)
			color = links->room1->color;
		else
			color = __WHITE;
		if (!(data->flags & FLAG_MARK_WAYS) ||
			(data->flags & FLAG_MARK_WAYS && links->room1->color == __BROWN
			&& links->room2->color == __BROWN))
			draw_line(&data->wnd.graph_img, links->room1->coord,
										links->room2->coord,
										color);
		++links;
		++iter;
	}
}
