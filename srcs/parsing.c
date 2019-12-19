/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 18:41:07 by ymanilow          #+#    #+#             */
/*   Updated: 2019/12/19 23:22:43 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void					ft_check_comment(t_data *data, char **line)
{
	ft_strdel(line);
	ft_printf("\n\ncomment hello\n\n");
	data->flag_comment = TRUE;
}

void					ft_check_ants(t_data *data, char **line)
{
	if (data->flag_link || data->flag_end ||
		data->flag_start || data->flag_ants)
		ft_error("ants must be first, and only ones!", 10);
	data->ants = ft_atoi(*line);
	ft_strdel(line);
}

void					ft_parsing(int ac, char **av, t_data *data)
{
	char		*line;
	int			fd;

	fd = 0;
	data->num_of_rooms = 1;
	data->col = 5;
	data->rooms = malloc(sizeof(t_room*) * data->col);
	if (ac != 2)
		ft_error("hernya vopros", 2);
	else if ((fd = open(av[1], O_RDONLY)) < 0)
		ft_error("check fd", 2);
	while (ft_get_next_line(fd, &line))
	{
		write(1, "ok\n", 3);
		if (*line == '#' && *(line + 1) != '#')
			ft_check_comment(data, &line);
		else if (ft_strequ("##start", line))
			ft_check_start(data, &line, fd);
		else if (ft_strequ("##end", line))
			ft_check_end(data, &line, fd);
		else if (ft_count_words(line, ' ') == 3)
			ft_check_room(data, &line);
		else if (ft_count_words(line, '-') == 2)
		{
			if (!data->flag_link)
				ft_pars_rooms(data);
			ft_check_links(data, &line);
		}
		else if (ft_count_words(line, ' ') == 1)
			ft_check_ants(data, &line);
	}
}