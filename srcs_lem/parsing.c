/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 20:12:52 by ymanilow          #+#    #+#             */
/*   Updated: 2020/03/14 19:36:59 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "graph.h"
#include "parsing.h"

static void				check_coord(t_data *data)
{
	int			i;
	int			j;

	i = -1;
	while (++i < data->graph.iter.col)
	{
		j = -1;
		while (++j < data->graph.iter.col)
		{
			if (i != j && data->graph.rooms[i]->coord.x ==
				data->graph.rooms[j]->coord.x &&
				data->graph.rooms[i]->coord.y == data->graph.rooms[j]->coord.y)
				ft_error("error", 6);
		}
	}
	buf_add_chr('\n', 1);
}

void					check_comment(t_data *data)
{
	buf_add_str(data->pars.line);
	buf_add_chr('\n', 1);
	ft_strdel(&data->pars.line);
}

static void				check_ants(t_data *data)
{
	__int128_t			num;

	if (data->flags.flag_ants)
		ft_error("error", 2);
	else if (data->flags.flag_links)
		ft_error("error", 2);
	else if (data->flags.flag_start)
		ft_error("error", 2);
	data->flags.flag_ants = TRUE;
	num = ft_atoi(data->pars.line);
	if (!ft_check_num(data->pars.line))
		ft_error("error", 2);
	if (num != (data->ants = num))
		ft_error("error", 2);
	if (data->ants <= 0)
		ft_error("error", 2);
	buf_add_str(data->pars.line);
	buf_add_chr('\n', 1);
	ft_strdel(&data->pars.line);
}

static void				ants(t_data *data)
{
	while (get_next_line(data->pars.fd, &data->pars.line) > 0 &&
			((*data->pars.line == '#') ||
			(ft_count_words(data->pars.line, ' ') == 1)))
	{
		if ((*data->pars.line == '#' && *(data->pars.line + 1) != '#'))
			check_comment(data);
		else if (*(data->pars.line) == '#' && *(data->pars.line + 1) == '#')
			check_side_room(data);
		else if (ft_count_words(data->pars.line, ' ') == 1)
		{
			check_ants(data);
			break ;
		}
	}
	if (data->pars.line)
		ft_strdel(&data->pars.line);
}

void					parsing(t_data *data)
{
	ants(data);
	while (get_next_line(data->pars.fd, &data->pars.line) > 0)
	{
		if (*(data->pars.line) == '#' && *(data->pars.line + 1) == '#')
			check_side_room(data);
		else if (*data->pars.line == '#' && *(data->pars.line + 1) != '#')
			check_comment(data);
		else if (ft_count_words(data->pars.line, ' ') == 3)
			check_rooms(data);
		else if (ft_count_words(data->pars.line, '-') == 2 &&
					ft_count_symbol(data->pars.line, '-') == 1)
			check_links(data);
		else
			ft_error("error", 1);
	}
	if (!data->flags.flag_links || !data->flags.flag_ants ||
									!data->flags.flag_room)
		ft_error("error", 2);
	if (data->pars.line)
		ft_strdel(&data->pars.line);
	check_coord(data);
}
