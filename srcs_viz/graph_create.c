/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 22:02:55 by dbendu            #+#    #+#             */
/*   Updated: 2020/02/26 15:31:42 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"
#include "private_graph.h"
#include "lemin.h"
#include "vector.h"

static int			get_ants(char *str)
{
	int				ants;

	while (TRUE)
	{
		if (*str == '#')
			free(str);
		else
		{
			ants = ft_atoi(str);
			free(str);
			break ;
		}
		get_next_line(0, &str);
	}
	return (ants);
}

static void			setup_graph_center(t_graph *graph)
{
	t_coord			*coord;
	size_t			iter;
	size_t			coords_amount;
	size_t			sum_x;
	size_t			sum_y;

	coords_amount = vec_size(graph->basic_coords);
	sum_x = 0;
	sum_y = 0;
	iter = 0;
	coord = graph->basic_coords;
	while (iter < coords_amount)
	{
		sum_x += coord->x;
		sum_y += coord->y;
		++iter;
		++coord;
	}
	graph->center.x = sum_x / coords_amount;
	graph->center.y = sum_y / coords_amount;
}

static char			*check_input(void)
{
	char			*str;

	while (TRUE)
	{
		get_next_line(0, &str);
		if (*str == '#')
			free(str);
		else if (!ft_isdigit(*str))
			exit(0);
		else
			break ;
	}
	return (str);
}

t_graph				graph_create(void)
{
	t_graph			graph;
	char			*str;

	str = check_input();
	ft_memset(&graph, 0, sizeof(t_graph));
	graph.ants = get_ants(str);
	get_rooms_and_coords(&graph, &str);
	graph.rooms_map = create_rooms_map(graph.rooms);
	graph.links = get_links(&graph.rooms_map, str);
	setup_graph_center(&graph);
	return (graph);
}
