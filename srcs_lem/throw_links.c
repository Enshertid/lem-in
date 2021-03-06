/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   throw_links.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 21:02:49 by ymanilow          #+#    #+#             */
/*   Updated: 2020/03/15 15:48:41 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ways.h"

static void				throw_links(t_way_room **start1, t_way_room **start2,
									t_way_room **end1, t_way_room **end2)
{
	(*start2)->next = (*start1)->next;
	(*start1)->next->prev = *start2;
	(*end1)->next = (*end2)->next;
	(*end2)->next->prev = *end1;
	while ((*end2)->prev->room != (*start2)->room)
	{
		*end2 = (*end2)->prev;
		free((*end2)->next);
	}
	free(*end2);
	while ((*start1)->prev->room != (*end1)->room)
	{
		*start1 = (*start1)->prev;
		free((*start1)->next);
	}
	free(*start1);
}

static void				pre_throw_links(t_way_room **first,
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
	while (tmp1->prev && tmp2->next
	&& tmp2->next->room == tmp1->prev->room)
	{
		tmp1 = tmp1->prev;
		tmp2 = tmp2->next;
	}
	throw_links(first, &tmp, &tmp1, &tmp2);
}

static short int		coincidence(t_way_room *first, t_way_room *second,
																	int col)
{
	while (col && second->next)
	{
		col--;
		second = second->next;
	}
	if (col && !second->next)
		return (2);
	if (first->room == second->room && first->prev &&
	first->prev->room == second->next->room)
		return (1);
	return (0);
}

static int				check_coincidence(t_way_room *first, t_ways *ways,
														t_bool **array, int i)
{
	int					col;
	int					flag;
	int					end;

	col = 0;
	end = ways->iters.i;
	while (end)
	{
		col++;
		i = -1;
		while (++i < ways->iters.i)
			if ((*array)[i])
			{
				flag = coincidence(first, ways->way_ar[i].head, col);
				if (flag == 2)
				{
					end--;
					(*array)[i] = FALSE;
				}
				else if (flag == TRUE)
					return (i);
			}
	}
	i = -1;
	return (i);
}

void					combine_ways_and_cut_common_link(t_way *first,
													t_ways *ways, int i)
{
	t_way_room		*tmp;
	t_way_room		*tmp1;
	t_bool			*array;

	check_repeat(first);
	array = ft_memalloc(sizeof(t_bool) * (ways->iters.i + 1));
	tmp = first->tail->prev;
	while (tmp->room != first->head->room)
	{
		ft_memset(array, TRUE, ways->iters.i);
		if ((i = check_coincidence(tmp, ways, &array, i)) >= 0)
		{
			pre_throw_links(&tmp, &ways->way_ar[i].head);
			tmp1 = first->tail;
			first->tail = ways->way_ar[i].tail;
			ways->way_ar[i].tail = tmp1;
			tmp = first->tail->prev;
		}
		else
			tmp = tmp->prev;
	}
	free(array);
}
