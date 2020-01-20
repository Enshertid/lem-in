/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 19:59:56 by ymanilow          #+#    #+#             */
/*   Updated: 2020/01/20 17:12:10 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "graph.h"

t_graph						set_graph()
{
	t_graph			graph;

	ft_memset(&graph, 0, sizeof(t_graph));
	graph.iter.col = 5000;
	graph.iter.i = 2;
	graph.rooms = ft_memalloc(sizeof(t_room*) * graph.iter.col);
	return(graph);
}
