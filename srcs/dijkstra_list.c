/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 15:59:52 by ymanilow          #+#    #+#             */
/*   Updated: 2020/01/17 16:04:07 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void					turn_list_del(t_turn_list **turn)
{
	t_turn_list *tmp;

	if((*turn)->next)
		(*turn)->next->last = (*turn)->last;
	tmp = *turn;
	*turn = tmp->next;
	tmp->next = NULL;
	free(tmp);
}

void					turn_list_add(t_turn_list **turn, t_room *room)
{
	t_turn_list *new;
	t_turn_list *tmp;

	tmp = (*turn)->last;
	new = malloc(sizeof(t_turn_list));
	new->room = room;
	new->next = NULL;
	(*turn)->last = new;
	tmp->next = new;
}

void					dijkstra_list(t_data *data)
{
	t_turn_list			*turn;
	int					j;

	turn = malloc(sizeof(t_turn_list));
	turn->room = &data->graph[0];
	turn->room->prev_way = NULL;
	turn->last = turn;
	turn->next = NULL;
	while (turn)
	{
		j = -1;
		while (++j < turn->room->iters.iter)
		{
			if ((turn->room->num_of_room + 1) < turn->room->links[j]->num_of_room)
			{
				turn->room->links[j]->num_of_room = turn->room->num_of_room + 1;
				if (turn->room->links[j]->flag_of_presence == 0)
				{
					turn_list_add(&turn, turn->room->links[j]);
					turn->room->links[j]->prev_way = turn->room;
					turn->room->links[j]->flag_of_presence = 1;
				}
			}
		}
		turn_list_del(&turn);
	}
	ft_printf("shortest way ==> %d \n", data->graph[data->iters.iter].num_of_room);
}