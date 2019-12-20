#include "vizu.h"

static void	get_ants(const int fd, t_data *data)
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
	room.name = ft_strdup(str);
	str = iter + 1;
	room.x = ft_atoi(str);
	str = ft_strchr(str, ' ') + 1;
	room.y = ft_atoi(str);
	room.links = vec_init(0, 0, sizeof(t_room*));
	return (room);
}

static char	*get_rooms(const int fd, t_data *data)
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


static void	get_links(const int fd, t_data *data, char *str)
{
	char *room1_name;
	char *room2_name;
	size_t	room1pos;
	size_t	room2pos;

	while (TRUE)
	{
		if (*str != '#')
		{
			room2_name = ft_strchr(str, '-') + 1;
			room2_name[-1] = '\0';
			room1_name = str;
			for (size_t i = 0; i < vec_size(data->rooms); ++i)
			{
				if (ft_strequ(data->rooms[i].name, room1_name))
					room1pos = i;
				else if (ft_strequ(data->rooms[i].name, room2_name))
					room2pos = i;
			}
//			printf("address1: %p\n", data->rooms + room2pos);
//			printf("name: %s\n", data->rooms[room2pos].name);
			vec_pushback(&(data->rooms[room1pos].links), &data->rooms[room2pos]);
			vec_pushback(&(data->rooms[room2pos].links), &data->rooms[room1pos]);

		}
		free(str);
		if (get_next_line(fd, &str) != 1)
			break;
	}
}

t_data		get_map(const char *file)
{
	t_data	data;
	char	*str;
	int		fd;

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
