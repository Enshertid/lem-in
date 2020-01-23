/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 18:41:07 by ymanilow          #+#    #+#             */
/*   Updated: 2020/01/23 21:56:24 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void					ft_check_comment(char **line)
{
	ft_printf("%s\n", *line);
	ft_strdel(line);
}

void					ft_check_ants(t_data *data, char **line)
{
	__int128_t			num;

	if (data->flags.flag_link || data->flags.flag_end || data->flags.flag_start ||
								data->flags.flag_ants || data->flags.flag_room)
		ft_error("ants must be first, and only ones!", 10);
	num = ft_atoi(*line);
	data->ants = num;
	if (data->ants != num)
		ft_error("overflow of int int num of ants\n", 10);
	data->flags.flag_ants = TRUE;
	ft_strdel(line);
}
void					check_flags(t_data *data)
{
	if (!data->flags.flag_start)
		ft_error("have no start\n", 2);
	if (!data->flags.flag_end)
		ft_error("have no end\n", 2);
	if (!data->flags.flag_link)
		ft_error("have no links\n", 2);
	if (!data->flags.flag_ants)
		ft_error("have no ants\n", 2);
}
void					ft_parsing(char **av, t_data *data)
{
	char		*line;

	if ((data->fd = open(av[1], O_RDONLY)) < 0)
		ft_error("fd error, you'r an asshole\n", 10);
	while ((ft_get_next_line(data->fd, &line)) == 1)
	{
		if (*line == '#' && *(line + 1) != '#')
			ft_check_comment(&line);
		else if (ft_strequ("##start", line))
			ft_check_start(data, &line);
		else if (ft_strequ("##end", line))
			ft_check_end(data, &line);
		else if (ft_count_words(line, ' ') == 3)
			ft_check_room(data, &line);
		else if (ft_count_words(line, '-') == 2)
		{
			if (!data->flags.flag_link)
				ft_pars_rooms(data);
			ft_check_links(data, &line);
		}
		else if (ft_count_words(line, ' ') == 1)
			ft_check_ants(data, &line);
		else
			ft_error("invalid input (empty line of something)\n", 2);
	}
	check_flags(data);
}