/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <dbendu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 18:47:10 by dbendu            #+#    #+#             */
/*   Updated: 2019/12/19 23:07:47 by dbendu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vizu.h"

t_room		get_room(char *str)
{
	t_room	room;
	char	*end;

	end = ft_strchr(str, ' ');
	*end = '\0';
	room.name = ft_strdup(str);
	str = end + 1;
	end = ft_strchr(str, ' ');
	*end = '\0';
	room.x = ft_atoi(str);
	str = end + 1;
	room.y = ft_atoi(str);
	return (room);
}

t_data		get_map(const char *file)
{
	t_data	data;
	t_room	room;
	char	*str;
	int fd = open(file, O_RDONLY);
	if (fd < 0)
		error(2, "Incorrect file", NULL, 0);

	data.rooms = vec_init(0, 2, sizeof(t_room));
	vec_set_size(data.rooms, 2);
	while (TRUE)
	{
		get_next_line(fd, &str);
		if (str[0] == '#')
		{
			free(str);
			continue;
		}
		data.ants = ft_atoi(str);
		 free(str);
		break;
	}
	while (get_next_line(fd, &str) == 1)
	{
		if (ft_strchr(str, '\n'))
			printf("%s\n", str);
		if (str[0] != '#' && !ft_strchr(str, ' '))
			break;
		if (str[0] != '#' || (str[0] == '#' && str[1] == '#'))
		{
			if (str[0] != '#')
				room = get_room(str);
			if (ft_strnequ(str, "##start", 8))
			{
				 free(str);
				get_next_line(fd, &str);
				room = get_room(str);
				data.rooms[0] = room;
			}
			else if (ft_strnequ(str, "##end", 6))
			{
				 free(str);
				get_next_line(fd, &str);
				room = get_room(str);
				data.rooms[1] = room;
			}
			else
				vec_pushback(&data.rooms, &room);
		}
		 free(str);
	}
	return (data);
}