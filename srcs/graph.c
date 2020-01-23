/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 19:59:56 by ymanilow          #+#    #+#             */
/*   Updated: 2020/01/23 22:03:03 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "graph.h"

void						turn_on_the_link(t_room *room_s, t_room *room_f)
{
	int					i;

	i = -1;
	while(++i < room_s->iter.i)
	{
		if (room_s->links[i].link->hash_index == room_f->hash_index &&
			ft_strequ(room_f->name, room_s->links[i].link->name))
			room_s->links[i].status = TRUE;
	}
}

void						turn_off_the_link(t_room *room_s, t_room *room_f)
{
	int					i;

	i = -1;
	while(++i < room_s->iter.i)
	{
		if (room_s->links[i].link->hash_index == room_f->hash_index &&
			ft_strequ(room_f->name, room_s->links[i].link->name))
			room_s->links[i].status = FALSE;
	}
}

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
