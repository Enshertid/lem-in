/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 19:09:22 by ymanilow          #+#    #+#             */
/*   Updated: 2019/12/22 13:09:29 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void					free_data(t_data *data)
{
	int				i;

	i = -1;
	while (++i < data->col)
	{
		free(data->rooms[i].links);
		free(data->rooms[i].name);
	}
	free(data->rooms);
	free(data->end.name);
	free(data->end.links);
}

int						main(int ac, char **av)
{
	t_data			data;

	if (ac < 0)
		ft_error("ahahahah\n", 100);
	ft_memset(&data, 0 , sizeof(t_data));
	data.num_of_rooms = 1;
	data.col = 5;
	data.rooms = malloc(sizeof(t_room) * data.col);
	data.rooms[0].name = ft_strnew(0);
	ft_parsing(av, &data);
	ft_printf("ants = %d\n" , data.ants);
	int i;
	i = -1;
	while (++i <= data.num_of_rooms)
	{
		if (data.rooms[i].iter < data.rooms[i].col)
			data.rooms[i].col = data.rooms[i].iter;
	}
	if (data.num_of_rooms < data.col)
		data.col = data.num_of_rooms;
	i = 0;
	ft_printf("name of room --> %s number of room i --> %d\n", data.rooms[i].name, data.rooms[i].num_of_room);
	i = -1;
	while (++i < data.rooms[0].col)
	{
		ft_printf("name of link of this room --> %s, number of room (link) --> %d\n", data.rooms[0].links[i].name,
				  data.rooms[0].links[i].num_of_room);
	}
	free_data(&data);
	return (0);
}