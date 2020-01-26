/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ways_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 17:25:00 by ymanilow          #+#    #+#             */
/*   Updated: 2020/01/25 18:06:25 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ways.h"

void				get_copy_of_way(t_way *prev, t_way *new)
{
	t_way_room			*tmp_prev;

	tmp_prev = prev->tail;
	while (tmp_prev)
	{
		way_point_add(new, way_point_create(tmp_prev->room));
		tmp_prev = tmp_prev->prev;
	}
}

void				throw_links(t_way_room **way_f, t_way_room **way_s)
{
	t_way_room				*tmp_f;
	t_way_room				*tmp_s;
	t_way_room				*tmp;
	ssize_t					i;

	tmp_f = *way_f;
	tmp_s = *way_s;
	i = -1;
	while(++i < tmp_f->room->iter.i)
		if (tmp_f->room->links[i].link == tmp_s->prev->room)
			tmp_f->room->links[i].condition = FALSE;
	i = -1;
	while (++i < tmp_s->prev->room->iter.i)
		if (tmp_s->prev->room->links[i].link == tmp_f->room)
			tmp_s->prev->room->links[i].condition = FALSE;
	tmp = tmp_f->next->next;
	tmp_f->next = tmp_s->next;
	tmp_s->prev->next = tmp;
}

void				combine_ways_and_cut_common_link(t_way *way_f, t_way *way_s)
{
	t_way_room				*tmp_f;
	t_way_room				*tmp_s;

	tmp_s = way_s->tail->prev;
	while (tmp_s->prev)
	{
		tmp_f = way_f->head->next;
		while (tmp_f->next)
		{
			if (tmp_s->room == tmp_f->room)
				throw_links(&tmp_f, &tmp_s);
			tmp_f = tmp_f->next;
		}
		tmp_s = tmp_s->prev;
	}
	tmp_f = way_f->head->next;
	tmp_s = way_f->head;
	while (tmp_f)
	{
		tmp_f->prev = tmp_s;
		tmp_f = tmp_f->next;
		tmp_s = tmp_s->next;
	}
	tmp_f = way_s->head->next;
	tmp_s = way_s->head;
	while (tmp_f)
	{
		tmp_f->prev = tmp_s;
		tmp_f = tmp_f->next;
		tmp_s = tmp_s->next;
	}
}