/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 20:12:52 by ymanilow          #+#    #+#             */
/*   Updated: 2020/01/20 14:02:24 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "graph.h"
#include "parsing.h"

void					check_flags(t_data *data)
{
	if (!data->flags.flag_links)
		ft_error("have no links\n", 2);
	else if (!data->flags.flag_ants)
		ft_error("have no ants\n", 2);
	else if (!data->flags.flag_end)
		ft_error("have no end room\n", 2);
	else if (!data->flags.flag_rooms)
		ft_error("have no rooms\n", 2);
	else if (!data->flags.flag_start)
		ft_error("have no start room\n",2 );
}

void					check_comment(t_data *data)
{
	ft_printf("%s\n", (data->pars.line));
	free(data->pars.line);
}

void					check_ants(t_data *data)
{
	__int128_t			num;

	if (data->flags.flag_ants)
		ft_error("ants again\n", 2);
	else if (data->flags.flag_links)
		ft_error("ants after links\n", 2);
	else if (data->flags.flag_start)
		ft_error("ants after start\n", 2);
	data->flags.flag_ants = TRUE;
	num = ft_atoi(data->pars.line);
	if (num != (data->ants = num))
		ft_error("overflow int at ants\n", 2);
	free(data->pars.line);
}

void					parsing(t_data *data, char **av)
{
	data->pars.fd = open(av[1], O_RDONLY);
	while(ft_get_next_line(data->pars.fd, &data->pars.line) > 0)
	{
		if (*(data->pars.line) == '#' && *(data->pars.line + 1) == '#')
			check_side_room(data);
		else if (*data->pars.line == '#' && *(data->pars.line + 1) != '#')
			check_comment(data);
		else if (ft_count_words(data->pars.line, ' ') == 3)
			check_rooms(data);
		else if (ft_count_words(data->pars.line, '-') == 2)
			check_links(data);
//			continue;
		else if (ft_count_words(data->pars.line, ' ') == 1)
			check_ants(data);
		else
			ft_error("invalid input\n", 1);
	}
	check_flags(data);
}
