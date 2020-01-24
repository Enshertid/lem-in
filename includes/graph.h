/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 19:57:23 by ymanilow          #+#    #+#             */
/*   Updated: 2020/01/24 16:51:27 by ymanilow         ###   ########.fr       */
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

typedef struct				s_link
{
	struct s_room			*link;
	t_bool					status;
	t_bool					condition;
}							t_link;

typedef struct				s_room
{
	char					*name;
	t_link					*links;
	t_link					prev_in_algo;
	t_iters					iter;
	t_coord					coord;
	int						hash_index;
	int						distance;
	int						flag;
	int						flag_of_way;
}							t_room;

typedef struct				s_graph
{
	t_room					**rooms;
	t_iters					iter;
}							t_graph;

t_graph						set_graph(void);
void						graph_free(t_graph *graph);

#endif
