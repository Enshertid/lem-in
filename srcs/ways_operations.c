/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ways_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 17:25:00 by ymanilow          #+#    #+#             */
/*   Updated: 2020/02/07 22:37:47 by ymanilow         ###   ########.fr       */
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

void				throw_links(t_way_room **way_s, t_way_room **way_f)
{
		t_way_room				*tmp_f;
		t_way_room				*tmp_s;
		t_way_room				*tmp;
		t_way_room				*tmp_tmp;
		ssize_t					i;

		tmp_f = *way_f;
		tmp_s = *way_s;
		i = -1;
		while(++i < tmp_f->prev->room->iter.i)
			if (tmp_f->prev->room->links[i].link == tmp_s->room)
				tmp_f->prev->room->links[i].cutout = TRUE;
		i = -1;
		while (++i < tmp_s->room->iter.i)
			if (tmp_s->room->links[i].link == tmp_f->prev->room)
				tmp_s->room->links[i].cutout = TRUE;
		tmp = tmp_f;
		tmp_f = tmp_f->prev;
		tmp->prev = tmp_s->prev;
		tmp_f->next = tmp_s;
		tmp_tmp = tmp_s->prev;
		tmp_tmp->next = tmp;
		tmp_s->prev = tmp_f;
		tmp_f->next = tmp_s->next->next;
		tmp_s = tmp_s->next;
		free(tmp_s->prev);
		tmp_s = tmp_s->next;
		free(tmp_s->prev);
		tmp_s->prev = tmp_f;
}

int					check_coincidence(t_way_room **first, t_way_room **second, int count)
{
	t_way_room *tmp;
	t_way_room *tmp_s;

	tmp_s = *second;
	while(count-- > 0 && tmp_s->next)
		tmp_s = tmp_s->next;
	tmp = *first;
	if (tmp->room == tmp_s->room && tmp->prev->room == tmp_s->next->room)
	{
		throw_links(&tmp, &tmp_s);
		return (1);
	}
	return(0);
}

void				combine_ways_and_cut_common_link(t_way *way_f, t_ways *ways)
{
	t_way_room			*tmp;
	int					count;
	int					i;
	t_bool				flag;

	tmp = way_f->tail->prev;
	while (tmp->room != way_f->head->room)
	{
		tmp = way_f->tail->prev;
		while (tmp->prev)
		{
			count = 0;
			flag = 0;
			i = -1;
			while (++i < ways->iters.i)
			{
				count++;
				if ((flag = check_coincidence(&tmp, &ways->way_ar[i].head, count)))
					break;
			}
			if (flag)
				break;
			tmp = tmp->prev;
		}
	}
}