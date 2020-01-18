/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_rooms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 21:31:52 by ymanilow          #+#    #+#             */
/*   Updated: 2020/01/18 19:57:37 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void					fill_room(t_data *data, t_room *room)
{
	__int128_t				num;

	data->pars.str = ft_strsplit(data->pars.line, ' ');
	room->name = ft_strdup(data->pars.str[0]);
	num = ft_atoi(data->pars.str[1]);
	if (num != (room->coord.x = num))
		ft_error("overflow int in x coord of room" , 4);
	num = ft_atoi(data->pars.str[2]);
	room->coord.y = num;
	if (num != room->coord.y)
		ft_error("overflow int in y coord of room", 4);
	room->hash_index = hash_index_create(data->hash.size, room->name);
	if (hash_check(&data->hash, room->hash_index, room->name))
		ft_error("same names in rooms\n", 4);
	hash_add(data->hash.hash_table, room);
}

void					check_start(t_data *data)
{
	free(data->pars.line);
	if (data->flags.flag_links)
		ft_error("start after links\n", 3);
	if (!data->flags.flag_ants)
		ft_error("start before ants\n", 3);
	while (ft_get_next_line(data->pars.fd, &data->pars.line) > 0 && *data->pars.line == '#'
						&& *data->pars.line + 1 != '#')
		check_comment(data);
	if (ft_count_words(data->pars.line, ' ') != 3)
		ft_error("wrong format of start\n",3);
	fill_room(data, &data->graph.rooms[0]);
	free(data->pars.line);
	ft_free(data->pars.str, 3);
}

void					check_end(t_data *data)
{
	free(data->pars.line);
	if (data->flags.flag_links)
		ft_error("end after links\n", 3);
	if (!data->flags.flag_ants)
		ft_error("end before ants\n", 3);
	while (ft_get_next_line(data->pars.fd, &data->pars.line) > 0 && *data->pars.line == '#'
			&& *data->pars.line + 1 != '#')
		check_comment(data);
	if (ft_count_words(data->pars.line, ' ') != 3)
		ft_error("wrong format of end\n",3);
	fill_room(data, &data->graph.rooms[1]);
	free(data->pars.line);
	ft_free(data->pars.str, 3);
}

void					check_side_room(t_data *data)
{
	if (ft_strequ(data->pars.line, "##start"))
	{
		if (data->flags.flag_start)
			ft_error("another start\n", 3);
		data->flags.flag_start = TRUE;
		check_start(data);
	}
	else if (ft_strequ(data->pars.line, "##end"))
	{
		if (data->flags.flag_end)
			ft_error("another end\n", 3);
		data->flags.flag_end = TRUE;
		check_end(data);
	}
}

void					check_rooms(t_data *data)
{
	if (data->flags.flag_links)
		ft_error("room after links\n", 3);
	if (!data->flags.flag_ants)
		ft_error("room before ants\n", 3);
	if (data->graph.iter.i == data->graph.iter.col)
		remalloc_of_graph(data);
	fill_room(data, &data->graph.rooms[data->graph.iter.i++]);
	free(data->pars.line);
	ft_free(data->pars.str, 3);
}