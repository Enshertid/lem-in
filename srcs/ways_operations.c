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
 			tmp_f->prev->room->links[i].condition = TRUE;
	i = -1;
	while (++i < tmp_s->room->iter.i)
		if (tmp_s->room->links[i].link == tmp_f->prev->room)
			tmp_s->room->links[i].condition = TRUE;
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

void				put_out_way1(t_way way)
{
	t_way_room *tmp;

	tmp = way.head;
	while (tmp)
	{
		ft_printf("%s\n",tmp->room->name);
		tmp = tmp->next;
	}
}

void				combine_ways_and_cut_common_link(t_way *way_f, t_way *way_s)
{
	t_way_room				*tmp_f;
	t_way_room				*tmp_s;
	t_way_room				*tmp;
	int						i;

	tmp_f = way_f->tail->prev;
	while (tmp_f->prev)
	{
		tmp_s = way_s->head->next;
		while (tmp_s->next)
		{
			if (tmp_f->room == tmp_s->room &&
			tmp_f->prev->room == tmp_s->next->room)
			{
				tmp_f = tmp_f->prev;
				tmp_s = tmp_s->prev;
				throw_links(&tmp_s->next, &tmp_f->next);
				if (tmp_f->next->room == tmp_f->prev->room)
				{
					tmp_f = tmp_f->prev;
					tmp = tmp_f->next;
					i = -1;
					while (++i < tmp_f->room->iter.i)
						if (tmp_f->room->links[i].link == tmp->room)
						{
							tmp_f->room->links[i].link->flags.flag_of_way = FALSE;
							tmp_f->room->links[i].condition = TRUE;
						}
					i = -1;
					while (++i < tmp->room->iter.i)
						if(tmp->room->links[i].link == tmp_f->room)
						{
							tmp->room->links[i].condition = TRUE;
							tmp->room->links[i].link->flags.flag_of_way = FALSE;
						}
					tmp->prev = NULL;
					tmp_f->next = tmp->next->next;
					tmp->next->next->prev = tmp_f;
					tmp->next->prev = NULL;
					tmp->next->next = NULL;
					free(tmp->next);
					free(tmp);
				}
			}
			tmp_s = tmp_s->next;
		}
		tmp_f = tmp_f->prev;
	}
}