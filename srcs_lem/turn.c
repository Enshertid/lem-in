/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 18:51:48 by ymanilow          #+#    #+#             */
/*   Updated: 2020/02/13 22:24:27 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "turn.h"

t_fork						**turn_create(int size)
{
	t_fork			**turn;

	turn = ft_memalloc(sizeof(t_fork*) * size);
	return (turn);
}

void						turn_free(t_turn *turn)
{
	turn->col = 0;
	turn->size = 0;
	free(turn->arr);
}

void						turn_add(t_turn *turn, t_fork *room,
													t_bool priority)
{
	int				i;
	int				j;

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

void						turn_del(t_turn *turn)
{
	ssize_t			i;
	ssize_t			j;

	if (turn->col > 0)
	{
		i = -1;
		j = 0;
		turn->arr[0]->flag = TRUE;
		while (++i < turn->col - 1 && ++j < turn->col)
			turn->arr[i] = turn->arr[j];
		turn->col--;
		turn->arr[turn->col] = NULL;
	}
	else if (turn->arr[0])
		turn->arr[0] = NULL;
}
