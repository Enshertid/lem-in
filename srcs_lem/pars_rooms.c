/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_rooms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 21:31:52 by ymanilow          #+#    #+#             */
/*   Updated: 2020/02/26 19:43:01 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static void				fill_room(t_data *data, t_room **room)
{
	__int128_t			num;

	if (!(*room = ft_memalloc(sizeof(t_room))))
		ft_error("error in malloc\n", 9);
	data->pars.str = ft_strsplit(data->pars.line, ' ');
	if (!((*room)->name = ft_strdup(data->pars.str[0])))
		ft_error("error in malloc\n", 9);
	num = ft_atoi(data->pars.str[1]);
	if (num != ((*room)->coord.x = num))
		ft_error("error", 4);
	num = ft_atoi(data->pars.str[2]);
	if (num != ((*room)->coord.y = num))
		ft_error("error", 4);
	if (!ft_check_num(data->pars.str[1]) || !ft_check_num(data->pars.str[2]))
		ft_error("error\n", 4);
	(*room)->hash_index = hash_index_create(data->hash.size, (*room)->name);
	if (hash_check(&data->hash, (*room)->hash_index, (*room)->name))
		ft_error("error\n", 4);
	hash_add(&data->hash, (*room));
	if (!((*room)->fork = ft_memalloc(sizeof(t_fork) * 2)))
		ft_error("error\n", 9);
	pre_fill_fork(room);
}

void					check_start(t_data *data)
{
	free(data->pars.line);
	if (data->flags.flag_links)
		ft_error("error\n", 3);
	if (!data->flags.flag_ants)
		ft_error("error\n", 3);
	while (get_next_line(data->pars.fd, &data->pars.line) > 0 &&
				!ft_strequ("##start", data->pars.line) &&
				!ft_strequ("##end", data->pars.line) &&
				(*data->pars.line == '#' || *data->pars.line + 1 == '#'))
		check_comment(data);
	if (ft_strequ("##start", data->pars.line) ||
		ft_strequ("##end", data->pars.line))
		ft_error("error\n", 3);
	if (ft_count_words(data->pars.line, ' ') != 3)
		ft_error("error\n", 3);
	fill_room(data, &data->graph.rooms[0]);
	data->graph.rooms[0]->fork->distance = 0;
	buf_add_str(data->pars.line);
	buf_add_chr('\n', 1);
	free(data->pars.line);
	ft_free(data->pars.str, 3);
}

void					check_end(t_data *data)
{
	free(data->pars.line);
	if (data->flags.flag_links)
		ft_error("error\n", 3);
	if (!data->flags.flag_ants)
		ft_error("error\n", 3);
	while (get_next_line(data->pars.fd, &data->pars.line) > 0 &&
					!ft_strequ("##start", data->pars.line) &&
					!ft_strequ("##end", data->pars.line) &&
					(*data->pars.line == '#' || *data->pars.line + 1 == '#'))
		check_comment(data);
	if (ft_strequ("##start", data->pars.line) ||
			ft_strequ("##end", data->pars.line))
		ft_error("error", 3);
	if (ft_count_words(data->pars.line, ' ') != 3)
		ft_error("error\n", 3);
	fill_room(data, &data->graph.rooms[1]);
	buf_add_str(data->pars.line);
	buf_add_chr('\n', 1);
	free(data->pars.line);
	ft_free(data->pars.str, 3);
}

void					check_side_room(t_data *data)
{
	if (ft_strequ(data->pars.line, "##start"))
	{
		if (data->flags.flag_start)
			ft_error("error\n", 3);
		data->flags.flag_start = TRUE;
		data->flags.flag_room = TRUE;
		buf_add_str(data->pars.line);
		buf_add_chr('\n', 1);
		check_start(data);
	}
	else if (ft_strequ(data->pars.line, "##end"))
	{
		if (data->flags.flag_end)
			ft_error("error\n", 3);
		data->flags.flag_end = TRUE;
		data->flags.flag_room = TRUE;
		buf_add_str(data->pars.line);
		buf_add_chr('\n', 1);
		check_end(data);
	}
	else if (data->pars.line && *data->pars.line == '#')
	{
		buf_add_str(data->pars.line);
		free(data->pars.line);
	}
}

void					check_rooms(t_data *data)
{
	if (data->flags.flag_links)
		ft_error("error\n", 3);
	if (!data->flags.flag_ants)
		ft_error("error\n", 3);
	data->flags.flag_room = 1;
	if (data->graph.iter.i == data->graph.iter.col)
		remalloc_of_graph(data);
	fill_room(data, &data->graph.rooms[data->graph.iter.i++]);
	buf_add_str(data->pars.line);
	buf_add_chr('\n', 1);
	free(data->pars.line);
	ft_free(data->pars.str, 3);
}
