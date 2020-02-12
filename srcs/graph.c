/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 19:59:56 by ymanilow          #+#    #+#             */
/*   Updated: 2020/02/12 15:30:53 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

void						duplicate_place_for_links(t_fork *first,
														t_fork *second)
{
	second->iter.col = first->iter.i + 1;
	if (!(second->links = ft_memalloc(sizeof(t_link) * second->iter.col)))
		ft_error("error in malloc\n", 9);
	second->iter.i = -1;
	while (++second->iter.i < second->iter.col - 1)
	{
		second->links[second->iter.i].link = first->links[second->iter.i].link;
		second->links[second->iter.i].status = TRUE;
	}
	free(first->links);
	first->iter.col = second->iter.col;
	if (!(first->links = ft_memalloc(sizeof(t_link) * first->iter.col)))
		ft_error("error in malloc\n", 9);
	first->iter.i = -1;
	while (++first->iter.i < first->iter.col - 1)
	{
		first->links[first->iter.i] = second->links[first->iter.i];
		first->links[first->iter.i].status = TRUE;
	}
	second->links[second->iter.i].link = first;
	second->links[second->iter.i].status = TRUE;
	first->in_out = FALSE;
	second->in_out = TRUE;
}

void						graph_free(t_graph *graph)
{
	int					i;

	i = -1;
	while (++i < graph->iter.col)
	{
		free(graph->rooms[i]->name);
		free(graph->rooms[i]->fork[0].links);
		free(graph->rooms[i]->fork[1].links);
		free(graph->rooms[i]->fork);
		free(graph->rooms[i]);
	}
	free(graph->rooms);
}

t_graph						set_graph(void)
{
	t_graph				graph;

	ft_memset(&graph, 0, sizeof(t_graph));
	graph.iter.col = 5000;
	graph.iter.i = 2;
	if (!(graph.rooms = ft_memalloc(sizeof(t_room*) * graph.iter.col)))
		ft_error("error in malloc\n", 9);
	return (graph);
}
