/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 18:51:48 by ymanilow          #+#    #+#             */
/*   Updated: 2020/01/23 23:11:15 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "turn.h"

t_room						**turn_create(int size)
{
	t_room				**turn;

	turn = ft_memalloc(sizeof(t_room*) * size);
	return (turn);
}
void 						turn_add(t_turn *turn, t_room *room, t_bool priority)
{
	int					i;
	int					j;

	if (!priority)
		turn->arr[turn->col++] = room;
	else
	{
		j = turn->col;
		i = turn->col;
		while (j-- > 1)
			turn->arr[i--] = turn->arr[j];
		turn->col++;
		turn->arr[1] = room;
	}
}

void 						turn_del(t_turn *turn)
{
	ssize_t					i;
	ssize_t					j;

	if (turn->col > 0)
	{
		i = -1;
		j = 0;
		while(++i < turn->col - 1 && ++j < turn->col)
			turn->arr[i] = turn->arr[j];
		turn->col--;
		turn->arr[turn->col] = NULL;
	}
	else if (turn->arr[0])
		turn->arr[0] = NULL;
}