/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 15:46:32 by ymanilow          #+#    #+#             */
/*   Updated: 2020/01/16 15:46:32 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "lem_in.h"

void					bfs(t_data *data, t_turn_array *turn)
{
	while (turn->col && !data->graph[data->iters.iter].num_on_the_search)
	{
		turn->i = -1;
		turn->j = -1;
		turn->count = turn->col;
		while(++turn->j < turn->count)
		{
			while (++turn->i < turn->array[turn->j]->iters.iter)
			{
				if (turn->array[turn->j]->links[turn->i]->num_on_the_search)
				{
					turn->array[turn->j]->flag_of_presence = 1;
					continue;
				}
				add_to_end_of_turn(turn,turn->array[turn->j]->
						links[turn->i],turn->array[turn->j]->num_on_the_search);
			}
			turn->i = -1;
		}
		while(turn->array[0]->flag_of_presence == 1 && turn->col != 0)
			delete_from_start(turn);
	}
}

void					bfs_array(t_data *data)
{
	t_turn_array	turn;

	ft_memset(&turn, 0, sizeof(t_turn_array));
	turn.array = ft_memalloc(sizeof(t_room*) * (data->iters.col));
	add_to_end_of_turn(&turn, &data->graph[0], -1);
	bfs(data, &turn);
	ft_printf("the shortest way is ===> %d\n",data->graph[data->iters.iter].num_on_the_search);
	free(turn.array);
}