#include "vizu.h"

static void		get_ants(const int fd, t_graph *graph)
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
		graph->ants = ft_atoi(str);
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
	return (room);
}

/*
 * because get_rooms can read string that contains first link
 * between rooms, i must return it to check later
 */
static char*	get_rooms(const int fd, t_graph *graph)
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
			graph->rooms[0] = get_room(str);
		}
		else if (ft_strequ(str, "##end"))
		{
			free(str);
			get_next_line(fd, &str);
			graph->rooms[1] = get_room(str);
		}
		else if (*str != '#')
		{
			room = get_room(str);
			vec_pushback(&graph->rooms, &room);
		}
		free(str);
	}
	return (str);
}

/*
 * last argument 'str' is string that was read last in get_rooms
 */
static	void	get_links(const int fd, t_graph *graph, char *str)
{
	char *name1;
	char *name2;
	ssize_t pos1 = -1;
	size_t pos2;

	for (size_t i = 0; i < vec_size(graph->rooms); ++i)
		graph->rooms[i].links = NULL;
	while (TRUE)
	{
		if (*str != '#')
		{
			name1 = str;
			name2 = ft_strchr(str, '-') + 1;
			name2[-1] = '\0';
			for (size_t i = 0; i < vec_size(graph->rooms); ++i)
			{
				if (ft_strequ(graph->rooms[i].name, name1))
					pos1 = i;
				else if (ft_strequ(graph->rooms[i].name, name2))
					pos2 = i;
			}
			if (pos1 >= 0) {
				if (!graph->rooms[pos1].links)
					graph->rooms[pos1].links = vec_init(0, 1, sizeof(t_graph*));
				void *ptr = graph->rooms + pos2;
				vec_pushback(&graph->rooms[pos1].links, &ptr);
				//				graph->rooms[pos1].links[0] = graph->rooms + pos2;
				if (!graph->rooms[pos2].links)
					graph->rooms[pos2].links = vec_init(0, 1, sizeof(t_graph*));
				ptr = graph->rooms + pos1;
				vec_pushback(&graph->rooms[pos2].links, &ptr);
//				graph->rooms[pos2].links[0] = graph->rooms + pos1;
			}
			pos1 = -1;
		}
		free(str);
		if (get_next_line(fd, &str) != 1)
			break;
	}
}

t_graph			get_graph(const char **argv)
{
	t_graph	graph;
	int		fd;
	char 	*str;

	fd = 0;
	while (*++argv)
		if (**argv && **argv != '-')
			fd = open(*argv, O_RDONLY);
	if (fd < 0)
		error(2, "invalid file", NULL, 0);
	else if (fd == 0)
		error(2, "missing file", NULL, 0);
	graph.rooms = vec_init(0, 2, sizeof(t_room));
	vec_set_size(graph.rooms, 2);
	get_ants(fd, &graph);
	str = get_rooms(fd, &graph);
	get_links(fd, &graph, str);
	return (graph);
}