/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 19:09:22 by ymanilow          #+#    #+#             */
/*   Updated: 2019/12/25 16:58:59 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void					free_data(t_data *data)
{
	int				i;

	i = -1;
	while (++i <= data->iters.iter)
	{
		free(data->rooms[i].links);
		free(data->rooms[i].name);
	}
	free(data->rooms);
}

void					data_first_set(t_data *data)
{
	ft_memset(data, 0 , sizeof(t_data));
	data->iters.iter = 1;
	data->iters.col = 1;
	data->rooms = ft_memalloc(sizeof(t_room) * data->iters.col);
	data->rooms[0].name = ft_strnew(0);
}

void					bfs(t_data *data, t_turn_array *turn)
{
	while (turn->col && !data->rooms[data->iters.iter].num_on_the_search)
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
		turn->j = -1;
		while(++turn->j < turn->col)
			if(turn->array[turn->j]->flag_of_presence == 1)
				delete_from_start(turn, &turn->j);
	}
}

void					bfs_array(t_data *data)
{
	t_turn_array	turn;

	ft_memset(&turn, 0, sizeof(t_turn_array));
	turn.array = ft_memalloc(sizeof(t_room*) * (data->iters.col));
	add_to_end_of_turn(&turn, &data->rooms[0], -1);
	bfs(data, &turn);
	ft_printf("the shortest way is ===> %d\n",data->rooms[data->iters.iter].num_on_the_search);
	free(turn.array);
}

void					bfs_list(t_data *data)
{
	t_turn_list *turn;

	turn = malloc(sizeof(t_turn_list));
	turn->next = NULL;
	turn->last = turn;
	turn->room = &data->rooms[0];
}

int						main(int ac, char **av)
{
	t_data			data;

	if (ac < 0)
		ft_error("ahahahah\n", 100);
	data_first_set(&data);
	ft_parsing(av, &data);
	if (!data.rooms[0].link_presence ||
		!data.rooms[data.iters.iter].link_presence)
		ft_error("have no links\n", 1000);
//	bfs_list(&data);
	bfs_array(&data);
	free_data(&data);
	ft_printf("all is fine\n");
	return (0);
}