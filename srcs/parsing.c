/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 20:12:52 by ymanilow          #+#    #+#             */
/*   Updated: 2020/01/17 21:35:35 by ymanilow         ###   ########.fr       */
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
		ft_error("have no links\n", 2);
	else if (!data->flags.flag_end)
		ft_error("have no end room\n", 2);
	else if (!data->flags.flag_rooms)
		ft_error("have no rooms\n", 2);
	else if (!data->flags.flag_start)
		ft_error("have no start room\n",2 );
}

void					check_comment(t_data *data)
{
	ft_printf("%s\n", *(data->line));
	free(*(data->line));
}

void					check_ants(t_data *data)
{
	__int128_t			num;

	num = ft_atoi(*(data->line));
	if (num != (data->ants = num))
		ft_error("overflow int at ants\n", 2);
	free(*(data->line));
}

void					parsing(t_data *data, char **av)
{
	data->fd = open(av[1], O_RDONLY);
	while(ft_get_next_line(data->fd, data->line) > 0)
	{
		if (**(data->line) == '#' && **(data->line + 1) == '#')
			check_side_room(data);
		else if (**data->line == '#' && **(data->line + 1) != '#')
			check_comment(data);
		else if (ft_count_words(*(data->line), ' ') == 1)
			check_ants(data);
		else if (ft_count_words(*(data->line), ' ') == 3)
			check_rooms(data);
		else if (ft_count_words(*(data->line), '-') == 2)
			check_links(data);
		else
			ft_error("invalid input\n", 1);
	}
	check_flags(data);
}
