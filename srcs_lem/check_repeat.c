/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costyl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 16:48:47 by ymanilow          #+#    #+#             */
/*   Updated: 2020/02/26 16:49:01 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ways.h"

void					check_repeat(t_way *way)
{
	t_way_room *tmp;
	t_way_room *tmp2;

	tmp = way->head;
	while (tmp->next)
	{
		while (tmp->room == tmp->next->room)
		{
			tmp2 = tmp->next;
			tmp->next = tmp2->next;
			tmp->next->prev = tmp;
			free(tmp2);
			tmp = tmp->next;
		}
		tmp = tmp->next;
	}
}
