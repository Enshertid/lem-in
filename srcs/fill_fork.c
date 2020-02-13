/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 20:50:05 by ymanilow          #+#    #+#             */
/*   Updated: 2020/02/13 20:55:51 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void					pre_fill_fork(t_room **room)
{
	int i;

	i = -1;
	while (++i < 2)
		(*room)->fork[i].distance = MAX_INT;
	i = -1;
	while (++i < 2)
		(*room)->fork[i].room = *room;
}
