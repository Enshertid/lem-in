/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_of_rooms.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 17:44:34 by ymanilow          #+#    #+#             */
/*   Updated: 2019/12/21 21:02:32 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void					ft_malloc_rooms(t_data *data)
{
	t_room		*tmp;

	tmp = ft_memalloc(sizeof(t_room) * (data->col + 1));
	int i = -1;
	while (++i < data->num_of_rooms)
			tmp[i].name = data->rooms[i].name;
	tmp = ft_memcpy(tmp, data->rooms, sizeof(t_room) * data->col);
	free(data->rooms);
	data->rooms = NULL;
	data->rooms = tmp;
	data->col ++;
}

void					ft_check_rooms(t_data *data)
{
	int				i;
	int				j;

	if (data->num_of_rooms >= data->col)
		ft_malloc_rooms(data);
	data->end.num_of_room = data->num_of_rooms;
	data->rooms[data->num_of_rooms] = data->end;
	i = -1;
	while (++i <= data->num_of_rooms)
	{
		j = i;
		while (++j <= data->num_of_rooms)
		{
			if (ft_strequ(data->rooms[i].name, data->rooms[j].name))
				ft_error("same name of rooms", 5);
			if (data->rooms[i].x == data->rooms[j].x && data->rooms[i].y == data->rooms[j].y)
				ft_error("same coordinates x or y\n", 5);
		}
	}
}

void					fill_room(t_room *room, char **str)
{
	__int128_t				num;

	room->name = ft_strdup(str[0]);
	if (ft_check_num(str[1]))
	{
		num = ft_atoi(str[1]);
		room->x = num;
		if (num != room->x)
			ft_error("overflow of int\n", 10);
	}
	else
		ft_error("not numeric in coord x\n", 10);
	if (ft_check_num(str[2]))
	{
		num = ft_atoi(str[2]);
		room->y = num;
		if (num != room->y)
			ft_error("overflow of int\n", 10);
	}
	else
		ft_error("not numeric in coord y\n", 10);
}

void					ft_add_room(t_data *data, char **line)
{
	char	**str;

	if (**line == 'L')
		ft_error("L in name of room", 3);
	if (data->flag_link == TRUE)
		ft_error("link before room", 3);
	if (data->col <= data->num_of_rooms)
		ft_malloc_rooms(data);
	str = ft_strsplit(*line, ' ');
	fill_room(&data->rooms[data->num_of_rooms], str);
	data->rooms[data->num_of_rooms].num_of_room = data->num_of_rooms;
	ft_free(str, 3);
	ft_strdel(line);
	data->num_of_rooms++;
}

void					ft_add_start(t_data *data, char **line)
{
	char			**str;

	ft_strdel(line);
	if (data->flag_start == TRUE)
		ft_error("another start", 3);
	data->flag_start = TRUE;
	if (ft_get_next_line(data->fd, line) && **line != '#' &&
			**line != 'L' &&  (ft_count_words(*line, ' ') != 3))
		ft_error("invalid start", 3);
	if (data->flag_link == TRUE)
		ft_error("link before room", 3);
	free(data->rooms[0].name);
	str = ft_strsplit(*line, ' ');
	fill_room(&data->rooms[0], str);
	data->rooms[0].num_of_room = 0;
	ft_free(str, 3);
	ft_strdel(line);
}

void					ft_add_end(t_data *data, char **line)
{
	char			**str;

	ft_strdel(line);
	if (data->flag_end == TRUE)
		ft_error("another end", 3);
	data->flag_end = TRUE;
	if (ft_get_next_line(data->fd, line) && **line != '#'&&
		**line != 'L' && (ft_count_words(*line, ' ') != 3))
		ft_error("invalid end", 3);
	if (data->flag_link == TRUE)
		ft_error("link before room", 3);
	str = ft_strsplit(*line, ' ');
	fill_room(&data->end, str);
	ft_free(str, 3);
	ft_strdel(line);
}
