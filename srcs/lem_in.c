/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 19:09:22 by ymanilow          #+#    #+#             */
/*   Updated: 2019/12/23 19:52:15 by ymanilow         ###   ########.fr       */
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
	free(data->end.links);
}

void					data_first_set(t_data *data)
{
	ft_memset(data, 0 , sizeof(t_data));
	data->iters.iter = 1;
	data->iters.col = 1;
	data->rooms = ft_memalloc(sizeof(t_room) * data->iters.col);
	data->rooms[0].name = ft_strnew(0);
}

void 					add_to_end_of_turn(t_data *data, t_room new)
{
	data->turn->turn_array[data->turn->col] = new;
	data->turn->col++;
}
void					delete_from_start(t_data *data)
{
	int					i;
	int					j;

	i = -1;
	j = 0;
	while(++i < data->turn->col)
		data->turn->turn_array[i] = data->turn->turn_array[++j];
}

void					turn(t_data *data)
{
	int			i;
	int			j;

	i = 0;
	add_to_end_of_turn(data, data->rooms[0]);
	while(data->turn->col && data->rooms[data->iters.col].num_on_the_search == 0)
	{
		j = -1;
		while(++j < data->turn->col)
			if(!data->turn->turn_array[j].num_on_the_search &&
					data->turn->turn_array[j].num_of_room != 0)
				delete_from_start(data);
		j = -1;
		while(++j < data->turn->turn_array[i].iters.col)
			if (!data->turn->turn_array[i].links[j].num_on_the_search)
				add_to_end_of_turn(data, data->turn->turn_array[i].links[j]);
		j = -1;
		while(++j < data->turn->turn_array[i].iters.col)
		{
			if (!data->turn->turn_array[i].links[j].num_on_the_search)
				data->turn->turn_array[i].links[j].num_on_the_search = i + 1;
		}
		if (data->turn->turn_array[0].num_of_room == 0)
			delete_from_start(data);
		if (data->rooms[++i].num_on_the_search == 0 && i != 0)
			add_to_end_of_turn(data, data->rooms[i]);
	}
	ft_printf("the shortest way is ===> %d\n", data->rooms[data->iters.col]);
}

void					remalloc_links(t_data *data)
{
	int			i;
	t_room		*tmp;

	i = -1;
	while(++i < data->iters.col)
		if (data->rooms[i].iters.iter < data->rooms[i].iters.col)
		{
			tmp = malloc(sizeof(t_room) * data->rooms[i].iters.iter);
			tmp->links = data->rooms[i].links;
			free(data->rooms[i].links);
			data->rooms[i].links = tmp;
			data->rooms[i].iters.col = data->rooms->iters.iter;
		}
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
//	remalloc_links(&data);
//	turn(&data);
	free_data(&data);
	ft_printf("all is fine\n");
	return (0);
}