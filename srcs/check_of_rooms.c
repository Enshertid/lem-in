/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_of_rooms.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 17:44:34 by ymanilow          #+#    #+#             */
/*   Updated: 2020/01/17 14:55:44 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void					ft_malloc_rooms(t_data *data)
{
	t_room		*tmp;

	tmp = malloc(sizeof(t_room) * (data->iters.col + 5));
	int i = -1;
	while (++i < data->iters.iter)
		tmp[i].name = data->graph[i].name;
	tmp = ft_memcpy(tmp, data->graph, sizeof(t_room) * data->iters.col);
	free(data->graph);
	data->graph = NULL;
	data->graph = tmp;
	data->iters.col += 5;
}

void					ft_pars_rooms(t_data *data)
{
	int				i;
	int				j;

	if (data->iters.iter >= data->iters.col)
		ft_malloc_rooms(data);
	data->graph[data->iters.iter] = data->end;
	data->end.num_of_room = data->iters.iter;
	data->end.num_on_array = data->iters.iter;
	i = -1;
	while (++i <= data->iters.iter)
	{
		j = i + 1;
		while (j <= data->iters.iter)
		{
			if (ft_strequ(data->graph[i].name, data->graph[j].name))
				ft_error("same name of rooms", 5);
			j++;
		}
	}
	i = -1;
	while (++i <= data->iters.iter)
	{
		data->graph[i].iters.iter = 0;
		data->graph[i].iters.col = 0;
		data->graph[i].link_presence = 0;
		data->graph[i].num_on_the_search = 0;
	}
}

void					check_int(t_room *room, char **str)
{
	__int128_t				num;

	room->name = ft_strdup(str[0]);
	if (ft_check_num(str[1]))
	{
		num = ft_atoi(str[1]);
		room->coord.x = num;
		if (num != room->coord.x)
			ft_error("overflow of int\n", 10);
	}
	if (ft_check_num(str[2]))
	{
		num = ft_atoi(str[2]);
		room->coord.y = num;
		if (num != room->coord.y)
			ft_error("overflow of int\n", 10);
	}
}

void					ft_check_room(t_data *data, char **line)
{
	char	**str;

	if (data->flags.flag_link == TRUE)
		ft_error("link before room", 3);
	if (data->iters.col <= data->iters.iter)
		ft_malloc_rooms(data);
	str = ft_strsplit(*line, ' ');
	check_int(&data->graph[data->iters.iter], str);
	data->graph[data->iters.iter].num_of_room = data->iters.iter;
	ft_free(str, 3);
	ft_strdel(line);
	data->graph[data->iters.iter].num_of_room = MAX_INT;
	data->graph[data->iters.iter].flag_of_presence = 0;
	data->graph[data->iters.iter].num_on_array = data->iters.iter;
	data->iters.iter++;

}

void					ft_check_start(t_data *data, char **line)
{
	char			**str;

	ft_strdel(line);
	if (data->flags.flag_start == TRUE)
		ft_error("another start", 3);
	data->flags.flag_start = TRUE;
	if (ft_get_next_line(data->fd, line) && **line != '#' &&  (ft_count_words(*line, ' ') != 3))
		ft_error("invalid start", 3);
	if (data->flags.flag_link == TRUE)
		ft_error("link before room", 3);
	free(data->graph[0].name);
	str = ft_strsplit(*line, ' ');
	check_int(&data->graph[0], str);
	data->graph[0].num_of_room = 0;
	data->graph[0].flag_of_presence = 0;
	ft_free(str, 3);
	ft_strdel(line);
}

void					ft_check_end(t_data *data, char **line)
{
	char			**str;

	ft_strdel(line);
	if (data->flags.flag_end == TRUE)
		ft_error("another end", 3);
	data->flags.flag_end = TRUE;
	if (ft_get_next_line(data->fd, line) && **line != '#' && (ft_count_words(*line, ' ') != 3))
		ft_error("invalid end", 3);
	if (data->flags.flag_link == TRUE)
		ft_error("link before room", 3);
	str = ft_strsplit(*line, ' ');
	check_int(&data->end, str);
	data->end.num_of_room = MAX_INT;
	data->end.flag_of_presence = 0;
	ft_free(str, 3);
	ft_strdel(line);
}
