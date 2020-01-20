/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ways.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 23:04:20 by ymanilow          #+#    #+#             */
/*   Updated: 2020/01/20 23:10:49 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ways.h"



void						room_add_to_way(t_way *way, t_room *room)
{
	t_way		*new;
	t_way		*tmp;

	if (way)
	{
		new = ft_memalloc(sizeof(t_way));
		new->room = room;
		new->next = NULL;
		tmp = way;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
	{
		way = ft_memalloc(sizeof(t_way));
		way->room = room;
		way->next = NULL;
	}
}