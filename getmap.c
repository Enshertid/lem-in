#include <string.h>
#include "vizu.h"

void get_ants(const int fd, t_data *data)
{
	char *str;

	while (TRUE)
	{
		get_next_line(fd, &str);
		if (*str == '#')
		{
			free(str);
			continue;
		}
		data->ants = ft_atoi(str);
		free(str);
		break;
	}
}

static t_room	get_room(char *str)
{
	t_room	room;
	char *iter;

	iter = ft_strchr(str, ' ');
	*iter = '\0';
	room.name = strdup(str);
	str = iter + 1;
	room.x = ft_atoi(str);
	str = ft_strchr(str, ' ') + 1;
	room.y = ft_atoi(str);
	return (room);
}

static char*	get_rooms(const int fd, t_data *data)
{
	char *str;
	t_room	room;

	while (TRUE)
	{
		get_next_line(fd, &str);
		if (*str != '#' && !ft_strchr(str, ' '))
			break;
		if (ft_strequ(str, "##start"))
		{
			free(str);
			get_next_line(fd, &str);
			data->rooms[0] = get_room(str);
		}
		else if (ft_strequ(str, "##end"))
		{
			free(str);
			get_next_line(fd, &str);
			data->rooms[1] = get_room(str);
		}
		else if (*str != '#')
		{
			room = get_room(str);
			vec_pushback(&data->rooms, &room);
		}
		free(str);
	}
	return (str);
}

static	void get_links(const int fd, t_data *data, char *str)
{
	char *name1;
	char *name2;
	ssize_t pos1 = -1;
	size_t pos2;

	for (size_t i = 0; i < vec_size(data->rooms); ++i)
		data->rooms[i].links = NULL;
	while (TRUE)
	{
		if (*str != '#')
		{
			name1 = str;
			name2 = ft_strchr(str, '-') + 1;
			name2[-1] = '\0';
			for (size_t i = 0; i < vec_size(data->rooms); ++i)
			{
				if (ft_strequ(data->rooms[i].name, name1))
					pos1 = i;
				else if (ft_strequ(data->rooms[i].name, name2))
					pos2 = i;
			}
			if (pos1 >= 0) {
				if (!data->rooms[pos1].links)
					data->rooms[pos1].links = malloc(sizeof(t_data *));
				data->rooms[pos1].links[0] = data->rooms + pos2;
				if (!data->rooms[pos2].links)
					data->rooms[pos2].links = malloc(sizeof(t_data *));
				data->rooms[pos2].links[0] = data->rooms + pos1;
			}
			pos1 = -1;
		}
		free(str);
		if (get_next_line(fd, &str) != 1)
			break;
	}
}

t_data		get_map(const char *file)
{
	t_data	data;
	int		fd;
	char 	*str;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		error(2, "Invalid file", NULL, 0);
	data.rooms = vec_init(0, 2, sizeof(t_room));
	vec_set_size(data.rooms, 2);
	get_ants(fd, &data);
	str = get_rooms(fd, &data);
	get_links(fd, &data, str);
	return (data);
}