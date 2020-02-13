/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <dbendu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 22:59:20 by dbendu            #+#    #+#             */
/*   Updated: 2020/02/13 21:34:10 by dbendu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

void					graph_destroy(t_graph *graph)
{
	size_t iter;

	iter = 0;
	while (iter < vec_size(graph->rooms))
	{
		free(graph->rooms[iter].name);
		if (graph->rooms[iter].links)
			vec_clear(&graph->rooms[iter].links);
		++iter;
	}
	vec_clear(&graph->rooms);
	vec_clear(&graph->links);
	vec_clear(&graph->basic_coords);
}
