/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_links.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 21:35:03 by ymanilow          #+#    #+#             */
/*   Updated: 2020/01/18 21:25:21 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void					finish_rooms(t_data *data)
{
	t_room			end;
//	int				i;

	data->flags.flag_links = TRUE;
	end = data->graph.rooms[data->graph.iter.i - 1];
	data->graph.rooms[data->graph.iter.i - 1] = data->graph.rooms[1];
	data->graph.rooms[1] = end;
	if (data->graph.iter.i < data->graph.iter.col)
		remalloc_graph(data);
//	i = -1;
//	while (++i < data->graph.iter.col)
//		data->graph.rooms[i].hash_index = hash_index_create(data->hash.size, data->graph.rooms[i].name);
//	i = -1;
//	while (++i < data->graph.iter.col)
//		hash_add(data->hash.hash_table, &data->graph.rooms[i]);
}

void					malloc_links(t_room *room)
{
	if (!room->iter.col)
		room->iter.col = 3;
	else
		room->iter.col *= 3;
	room->links = ft_memalloc(sizeof(t_room) * room->iter.col);
}

int						check_repeated_link(t_room *room_f, t_room *room_s)
{
	int				i;
	int				flag;

	i = -1;
	flag = 0;
	while (++i < room_f->iter.i)
		if (ft_strequ(room_f->links[i]->name, room_s->name))
			flag = 1;
	i = -1;
	while (++i < room_s->iter.i)
		if (ft_strequ(room_s->links[i]->name , room_s->name))
			flag = 1;
	return (flag);
}

void					print_hash_table(t_data *data)
{
	int					i;

	i = -1;
	while (++i < data->graph.iter.col)
		ft_printf("%s\n", data->hash.hash_table[data->graph.rooms[i].hash_index].room->name);
}

void					check_links(t_data *data)
{
	ft_printf("hello\n");
	if (!data->flags.flag_links)
		finish_rooms(data);
	print_hash_table(data);
	data->pars.str = ft_strsplit(data->pars.line, '-');
	data->pars.hash_f = hash_index_create(data->hash.size,
								data->pars.str[0]);
	data->pars.hash_s = hash_index_create(data->hash.size,
								data->pars.str[1]);
	if (!hash_check(&data->hash, data->pars.hash_f, data->pars.str[0]))
		ft_error("wrong first room in link\n", 5);
	if (!hash_check(&data->hash, data->pars.hash_s, data->pars.str[1]))
		ft_error("wrong second room in link\n", 5);
	data->pars.room_f = hash_search(&data->hash, data->pars.hash_f,
								data->pars.str[0]);
	data->pars.room_s = hash_search(&data->hash, data->pars.hash_s,
								data->pars.str[1]);
	if (data->pars.room_f->iter.i == data->pars.room_f->iter.col)
		malloc_links(data->pars.room_f);
	if (data->pars.room_s->iter.i == data->pars.room_s->iter.col)
		malloc_links(data->pars.room_s);
	if (check_repeated_link(data->pars.room_f, data->pars.room_s))
		ft_error("link has been repeat\n", 5);
	data->pars.room_f->links[data->pars.room_f->iter.i++] = data->pars.room_s;
	data->pars.room_s->links[data->pars.room_s->iter.i++] = data->pars.room_f;
}