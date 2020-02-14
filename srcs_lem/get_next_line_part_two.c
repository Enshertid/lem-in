/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_part_two.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 21:11:49 by ymanilow          #+#    #+#             */
/*   Updated: 2020/02/13 21:24:22 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void					ft_lstpurge(t_list **list)
{
	register t_list		*iter;
	register t_list		*temp;

	if (!list || !*list)
		return ;
	iter = *list;
	while (iter)
	{
		temp = iter->next;
		free(iter->content);
		free(iter);
		iter = temp;
	}
	*list = NULL;
}

static void				ft_replace(t_list **to, t_list **from)
{
	free((*to)->content);
	(*to)->content = (*from)->content;
	(*to)->content_size = (*from)->content_size;
	(*to)->next = (*from)->next;
	free(*from);
}

void					ft_lstdelete(t_list **list, t_list **del)
{
	t_list				*iter;

	if (!list || !*list || !del || !*del)
		return ;
	if (*del == (*list))
		ft_lstpop(list);
	else if (*del == (*list)->end)
		ft_lstpopback(list);
	else
	{
		iter = *list;
		while (iter && iter != *del)
			iter = iter->next;
		if (iter)
			ft_replace(&iter, &(iter->next));
	}
	*del = NULL;
}
