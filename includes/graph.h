/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 19:57:23 by ymanilow          #+#    #+#             */
/*   Updated: 2020/02/10 17:30:13 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GRAPH_H
#define GRAPH_H

#include "libft.h"

typedef struct				s_flags_algo
{
	t_bool					in_out_switch;
	t_bool					flag_of_way;
	t_bool					flag;
}							t_flags_algo;

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
	struct s_fork			*link;
	t_bool					status;
}							t_link;

typedef struct				s_fork
{
	t_link					*links;
	t_iters					iter;
	int						distance;
	int						num_of_way;
	struct s_room			*room;
	struct s_room			*prev_in_algo;
}							t_fork;

typedef struct				s_room
{
	char					*name;
	t_fork					*fork;
	t_coord					coord;
	t_flags_algo			flags;
	int						hash_index;
}							t_room;



typedef struct				s_graph
{
	t_room					**rooms;
	t_iters					iter;
}							t_graph;

t_graph						set_graph(void);
void						graph_free(t_graph *graph);
void						duplicate_place_for_links(t_fork *first, t_fork *second);
#endif
