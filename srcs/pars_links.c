/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_links.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 21:35:03 by ymanilow          #+#    #+#             */
/*   Updated: 2020/02/10 18:37:32 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void					finish_rooms(t_data *data)
{
	t_room			*end;

	if (!data->flags.flag_end)
		ft_error("have no end room\n", 2);
	else if (!data->flags.flag_start)
		ft_error("have no start room\n",2 );
	data->flags.flag_links = TRUE;
	end = data->graph.rooms[data->graph.iter.i - 1];
	data->graph.rooms[data->graph.iter.i - 1] = data->graph.rooms[1];
	data->graph.rooms[1] = end;
	if (data->graph.iter.i < data->graph.iter.col)
		final_remalloc_graph(data);
}

void			malloc_links(t_room *room)
{
	t_link					*links;
	int						i;

	if (!room->fork[0].iter.col)
		room->fork[0].iter.col = 3;
	else
		room->fork[0].iter.col *= 2;
	links = ft_memalloc(sizeof(t_link) * room->fork[0].iter.col);
	i = -1;
	if (room->fork[0].iter.col != 3)
	{
		while (++i < room->fork[0].iter.i)
			links[i].link = room->fork[0].links[i].link;
		i = -1;
		while (++i < room->fork[0].iter.col)
			links[i].status = TRUE;
		free(room->fork[0].links);
		room->fork[0].links = NULL;
	}
	else
		while (++i < room->fork[0].iter.col)
			links[i].status = TRUE;
	room->fork[0].links = links;
}

int						check_repeated_link(t_room *room_f, t_room *room_s)
{
	int				i;
	int				flag;

	i = -1;
	flag = 0;
	while (++i < room_f->fork[0].iter.i)
		if (ft_strequ(room_f->fork[0].links[i].link->room->name, room_s->name))
			flag = 1;
	i = -1;
	while (++i < room_s->fork[0].iter.i)
		if (ft_strequ(room_s->fork[0].links[i].link->room->name , room_f->name))
			flag = 1;
	return (flag);
}

void					pars_link(t_data *data)
{
	data->pars.str = ft_strsplit(data->pars.line, '-');
	data->pars.hash_f = hash_index_create(data->hash.size,
			data->pars.str[0]);
	data->pars.hash_s = hash_index_create(data->hash.size,
			data->pars.str[1]);
	if (!(data->pars.room_f = hash_search(&data->hash, data->pars.hash_f,
			data->pars.str[0])))
		ft_error("wrong first room in link\n", 5);
	if (!(data->pars.room_s = hash_search(&data->hash, data->pars.hash_s,
			data->pars.str[1])))
		ft_error("wrong second room in link\n", 5);
	if (data->pars.room_f->fork[0].iter.i ==
			data->pars.room_f->fork[0].iter.col)
		malloc_links(data->pars.room_f);
	if (data->pars.room_s->fork[0].iter.i ==
			data->pars.room_s->fork[0].iter.col)
		malloc_links(data->pars.room_s);
	if (check_repeated_link(data->pars.room_f, data->pars.room_s))
		ft_error("link has been repeat\n", 5);
	data->pars.room_f->fork[0].links[data->pars.room_f->fork[0].iter.i++].link
												= &data->pars.room_s->fork[0];
	data->pars.room_s->fork[0].links[data->pars.room_s->fork[0].iter.i++].link
												= &data->pars.room_f->fork[0];
	free(data->pars.line);
	ft_free(data->pars.str, 2);
}

void					check_links(t_data *data)
{
	if (!data->flags.flag_links)
		finish_rooms(data);
	pars_link(data);
	while (get_next_line(data->pars.fd, &data->pars.line) > 0 &&
			((ft_count_words(data->pars.line, '-') == 2 &&
			ft_count_symbol(data->pars.line, '-') == 1) ||
			(*data->pars.line == '#' && *(data->pars.line + 1) != '#')))
	{
		if (ft_count_words(data->pars.line, '-') == 2 &&
			ft_count_symbol(data->pars.line, '-') == 1)
			pars_link(data);
		else if (*data->pars.line == '#' && *(data->pars.line + 1) != '#')
			check_comment(data);
	}
}