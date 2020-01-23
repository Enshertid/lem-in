/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ways.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 23:00:09 by ymanilow          #+#    #+#             */
/*   Updated: 2020/01/23 22:13:47 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WAYS_H
#define WAYS_H

#include "graph.h"

typedef struct					s_way
{
	struct s_way				*next;
	t_room						*room;
}								t_way;

typedef struct					s_ways
{
	t_iters						iters;
	t_way						**way_ar;
}								t_ways;

void							ways_array_malloc(t_ways *ways);
void							room_add_to_way(t_way **way, t_way *new);

int								lenght_of_way(t_way *way);
void							show_the_way(t_way *way);

t_way							*point_of_way_create(t_room *room);
void							turn_way_to_state(t_way **way, t_bool state);
void							get_way(t_graph *graph, t_ways *ways, int num, t_bool state);

#endif
