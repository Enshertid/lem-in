/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ways.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 23:00:09 by ymanilow          #+#    #+#             */
/*   Updated: 2020/01/24 21:24:46 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WAYS_H
#define WAYS_H

#include "graph.h"

typedef struct					s_way_room
{
	struct s_way_room			*next;
	struct s_way_room			*prev;
	t_room						*room;
}								t_way_room;

typedef struct					s_way
{
	t_way_room					*head;
	t_way_room					*tail;
}								t_way;

typedef struct					s_ways
{
	t_way						*way_ar;
	t_iters						iters;
	int 						weight;
}								t_ways;

typedef struct					s_storage_w
{
	t_ways						*ways;
	t_iters						iters;
}								t_storage_w;

void							way_point_add(t_way *storage, t_way_room *new);
t_way_room						*way_point_create(t_room *room);

void							combine_ways_and_cut_common_link(t_way *way_f,
																t_way *way_s);

void							way_storage_set(t_graph *graph, t_storage_w *ways);
void							way_storage_free(t_storage_w *ways);
void							way_clear(t_way *way);

void							get_copy_of_way(t_way *prev, t_way *new);
int								way_weight(t_way *way);

#endif
