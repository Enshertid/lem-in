/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 19:59:56 by ymanilow          #+#    #+#             */
/*   Updated: 2020/01/20 18:11:39 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "graph.h"

void						graph_free(t_graph *graph)
{
	int					i;

	i = -1;
	while(++i < graph->iter.col)
	{
		free(graph->rooms[i]->name);
		free(graph->rooms[i]->links);
		free(graph->rooms[i]);
	}
	free(graph->rooms);
}

t_graph						set_graph(void)
{
	t_graph			graph;

	ft_memset(&graph, 0, sizeof(t_graph));
	graph.iter.col = 5000;
	graph.iter.i = 2;
	graph.rooms = ft_memalloc(sizeof(t_room*) * graph.iter.col);
	return(graph);
}
