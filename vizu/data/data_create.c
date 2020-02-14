/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <dbendu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 22:08:13 by dbendu            #+#    #+#             */
/*   Updated: 2020/02/14 01:39:46 by dbendu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "private_data.h"

t_data				data_create(char **argv)
{
	t_data			data;

	ft_memset(&data, 0, sizeof(t_data));
	data.wnd = wnd_create();
	data.flags = get_flags(argv);
	data.graph = graph_create();
	data.animation = animation_create(data.graph.ants, &data.graph.rooms_map,
										data.graph.rooms);
	apply_flags(&data);
	return (data);
}
