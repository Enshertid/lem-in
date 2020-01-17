/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 19:57:23 by ymanilow          #+#    #+#             */
/*   Updated: 2020/01/17 21:48:25 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GRAPH_H
#define GRAPH_H

#include "libft.h"

typedef struct				s_iters
{
	int						i;
	int 					col;
}							t_iters;

typedef struct				s_coord
{
	int						x;
	int						y;
}							t_coord;

typedef struct				s_room
{
	char					*name;
	struct s_room			**links;
	t_coord					coord;
}							t_room;

typedef struct				s_graph
{
	t_room					*rooms;
	t_iters					iter;
}							t_graph;

t_graph						set_graph();

#endif
