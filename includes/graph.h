/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 19:57:23 by ymanilow          #+#    #+#             */
/*   Updated: 2020/01/21 17:01:52 by ymanilow         ###   ########.fr       */
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

//typedef struct s_room;
//typedef struct s_room t_room;
//
//struct s_link;
//typedef struct s_link t_link;

typedef struct				s_link
{
	struct s_room			*link;
	int						status;
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
}							t_room;

typedef struct				s_graph
{
	t_room					**rooms;
	t_iters					iter;
}							t_graph;

t_graph						set_graph(void);
void						graph_free(t_graph *graph);

void						turn_on_the_link(t_room *room_s, t_room *room_f);
void						turn_off_the_link(t_room *room_s, t_room *room_f);

#endif
