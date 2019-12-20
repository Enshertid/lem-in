/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_of_rooms.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 17:44:34 by ymanilow          #+#    #+#             */
/*   Updated: 2019/12/20 16:51:19 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void					ft_malloc_rooms(t_data *data)
{
	t_room		*tmp;

	tmp = malloc(sizeof(t_room) * (data->col + 5));
	int i = -1;
	while (++i < data->num_of_rooms )
			tmp[i].name = data->rooms[i].name;
	tmp = ft_memcpy(tmp, data->rooms, sizeof(t_room) * data->col);
	free(data->rooms);
	data->rooms = NULL;
	data->rooms = tmp;
	data->col += 5;
}

void					ft_pars_rooms(t_data *data)
{
	int				i;
	int				j;

	if (data->num_of_rooms >= data->col)
		ft_malloc_rooms(data);
	data->rooms[data->num_of_rooms] = data->end;
	i = -1;
	while (++i <= data->num_of_rooms)
	{
		j = i + 1;
		while (j <= data->num_of_rooms)
		{
			if (ft_strequ(data->rooms[i].name, data->rooms[j].name))
				ft_error("same name of rooms", 5);
			j++;
		}
	}
	i = -1;
	while (++i <= data->num_of_rooms)
	{
		data->rooms[i].iter = 0;
		data->rooms[i].col = 0;
		data->rooms[i].link_presence = 0;
		data->rooms[i].ant_presence = 0;
	}
}

void					ft_check_room(t_data *data, char **line)
{
	char	**str;

	if (data->flag_link == TRUE)
		ft_error("link before room", 3);
	if (data->col <= data->num_of_rooms)
		ft_malloc_rooms(data);
	str = ft_strsplit(*line, ' ');
	data->rooms[data->num_of_rooms].name = ft_strdup(str[0]);
	if (ft_check_num(str[1]))
		data->rooms[data->num_of_rooms].width = ft_atoi(str[1]);
	if (ft_check_num(str[2]))
		data->rooms[data->num_of_rooms].hight = ft_atoi(str[2]);
	data->rooms[data->num_of_rooms].num_of_room = data->num_of_rooms;
	ft_free(&str, 3);
	ft_strdel(line);
	data->num_of_rooms++;
}

void					ft_check_start(t_data *data, char **line, int fd)
{
	char			**str;

	ft_strdel(line);
	if (data->flag_start == TRUE)
		ft_error("another start", 3);
	data->flag_start = TRUE;
	if (ft_get_next_line(fd, line) && **line != '#' &&  (ft_count_words(*line, ' ') != 3))
		ft_error("invalid start", 3);
	if (data->flag_link == TRUE)
		ft_error("link before room", 3);
	free(data->rooms[0].name);
	str = ft_strsplit(*line, ' ');
	data->rooms[0].name = ft_strdup(str[0]);
	if (ft_check_num(str[1]))
		data->rooms[0].width = ft_atoi(str[1]);
	if (ft_check_num(str[2]))
		data->rooms[0].hight = ft_atoi(str[2]);
	data->rooms[0].num_of_room = 0;
	ft_free(&str, 3);
	ft_strdel(line);
}

void					ft_check_end(t_data *data, char **line, int fd)
{
	char			**str;

	ft_strdel(line);
	if (data->flag_end == TRUE)
		ft_error("another end", 3);
	data->flag_end = TRUE;
	if (ft_get_next_line(fd, line) && **line != '#' && (ft_count_words(*line, ' ') != 3))
		ft_error("invalid end", 3);
	if (data->flag_link == TRUE)
		ft_error("link before room", 3);
	str = ft_strsplit(*line, ' ');
	data->end.name = ft_strdup(str[0]);
	if (ft_check_num(str[1]))
		data->end.width = ft_atoi(str[1]);
	if (ft_check_num(str[2]))
		data->end.hight = ft_atoi(str[2]);
	ft_free(&str, 3);
	ft_strdel(line);
}
