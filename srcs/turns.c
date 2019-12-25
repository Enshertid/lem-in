/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 22:45:36 by ymanilow          #+#    #+#             */
/*   Updated: 2019/12/25 15:29:46 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void 					add_to_end_of_turn(t_turn_array *turn, t_room *new, int num)
{
	new->num_on_the_search = ++num;
	turn->array[turn->col] = new;
	turn->col++;
}
void					delete_from_start(t_turn_array *turn, int *num)
{
	int					i;
	int					j;

	i = -1;
	j = 0;
	while(++i < turn->col)
		turn->array[i] = turn->array[++j];
	turn->col--;
	(*num)--;
}
