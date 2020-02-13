/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   throw_links.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 21:02:49 by ymanilow          #+#    #+#             */
/*   Updated: 2020/02/13 21:03:28 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ways.h"

void				throw_links(t_way_room **start1, t_way_room **start2,
									t_way_room **end1, t_way_room **end2)
{
	(*start2)->next = (*start1)->next;
	(*start1)->next->prev = *start2;
	(*end1)->next = (*end2)->next;
	(*end2)->next->prev = *end1;
	while ((*end2)->prev && (*end2)->prev->room != (*start2)->room)
	{
		*end2 = (*end2)->prev;
		free((*end2)->next);
	}
	free(*end2);
	while ((*start1)->prev && (*start1)->prev->room != (*end1)->room)
	{
		*start1 = (*start1)->prev;
		free((*start1)->next);
	}
	free(*start1);
}

void				pre_throw_links(t_way_room **first,
											t_way_room **second)
{
	t_way_room			*tmp;
	t_way_room			*tmp1;
	t_way_room			*tmp2;

	tmp = *second;
	while ((*first)->room != tmp->room)
		tmp = tmp->next;
	tmp1 = *first;
	tmp2 = tmp;
	while (tmp1->prev->prev && tmp2->next->next && tmp2->next->room ==
															tmp1->prev->room)
	{
		tmp1 = tmp1->prev;
		tmp2 = tmp2->next;
	}
	throw_links(first, &tmp, &tmp1, &tmp2);
}

short int			coincidence(t_way_room *first, t_way_room *second,
																	int col)
{
	while (col && second->next)
	{
		col--;
		second = second->next;
	}
	if (col && !second->next)
		return (1);
	if (first->room == second->room && first->prev == second->next)
		return (2);
	return (0);
}

int					check_coincidence(t_way_room *first, t_ways *ways,
														t_bool **array, int i)
{
	int					col;
	int					flag;
	int					end;

	col = 0;
	end = ways->iters.i;
	while (end)
	{
		flag = FALSE;
		col++;
		i = -1;
		while (!flag && ++i < ways->iters.i)
			if ((*array)[i])
				flag = coincidence(first, ways->way_ar[i].head, col);
		if (flag == 2)
			break ;
		if (flag == TRUE)
		{
			end--;
			(*array)[i] = FALSE;
			i = -1;
		}
	}
	return (i);
}

void				combine_ways_and_cut_common_link(t_way *way_f,
														t_ways *ways, int i)
{
	t_way_room			*tmp;
	t_way_room			*tmp1;
	t_bool				*array;

	array = ft_memalloc(sizeof(t_bool) * ways->iters.i);
	ft_memset(array, TRUE, ways->iters.i);
	tmp = way_f->tail->prev;
	while (tmp->room != way_f->head->room)
	{
		if ((i = check_coincidence(tmp, ways, &array, i)) >= 0)
		{
			pre_throw_links(&tmp, &ways->way_ar[i].head);
			ft_memset(array, TRUE, ways->iters.i);
			tmp1 = way_f->tail;
			way_f->tail = ways->way_ar[i].tail;
			ways->way_ar[i].tail = tmp1;
			tmp = way_f->tail->prev;
		}
		else
		{
			tmp = tmp->prev;
			ft_memset(array, TRUE, ways->iters.i);
		}
	}
	free(array);
}
