/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 22:59:20 by dbendu            #+#    #+#             */
/*   Updated: 2020/02/25 21:45:31 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"
#include "vector.h"

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
