/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 19:59:56 by ymanilow          #+#    #+#             */
/*   Updated: 2020/02/10 19:30:43 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "graph.h"

void						duplicate_place_for_links(t_fork *first, t_fork *second)
{
	second->iter.col = first->iter.i;
	ft_printf("%s\n", first->room->name);
	second->links = ft_memalloc(sizeof(t_link) * (second->iter.col + 1));
	second->iter.i = -1;
	while (++second->iter.i < second->iter.col)
	{
		second->links[second->iter.i].link = first->links[second->iter.i].link;
		second->links[second->iter.i].status = TRUE;
	}
	second->links[second->iter.i].link = first;
	second->links[second->iter.col].status = TRUE;
	free(first->links);
	first->iter.col = second->iter.col;
	first->links = ft_memalloc(sizeof(t_link) * first->iter.col);
	first->iter.i = -1;
	while (++first->iter.i < first->iter.col)
	{
		first->links[first->iter.i] = second->links[first->iter.i];
		first->links[first->iter.i].status = TRUE;
	}
	first->iter.i = 0;
	second->iter.i = 0;
	second->iter.col++;
}

void						graph_free(t_graph *graph)
{
	int					i;

	i = -1;
	while(++i < graph->iter.col)
	{
		free(graph->rooms[i]->name);
		free(graph->rooms[i]->fork[0].links);
//		free(graph->rooms[i]->fork[0].prev_in_algo);
		free(graph->rooms[i]->fork[1].links);
//		free(graph->rooms[i]->fork[1].prev_in_algo);
		free(graph->rooms[i]->fork);
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
