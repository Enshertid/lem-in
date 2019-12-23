#include "vizu.h"

static void		find_best_z_scale(t_data *data)
{
	size_t	sum;
	size_t	i;

	if (!(data->flags & FLAG_Z))
		return ;
	sum = 0;
	i = 0;
	while (i < vec_size(data->graph.rooms))
	{
		sum += data->graph.rooms[i].x + data->graph.rooms[i].y;
		++i;
	}
	data->graph.z_scale = sum / 2;
}

static void		set_coords(t_data *data)
{
	size_t		i;
	size_t		rooms;
	t_coord		coord;

	srand(time(NULL));
	rooms = vec_size(data->graph.rooms);
	data->graph.coords = vec_init(0, rooms, sizeof (t_coord));
	i = 0;
	if (!(data->flags & FLAG_Z))
		while (i < rooms)
		{
			coord.x = data->graph.rooms[i].x;
			coord.y = data->graph.rooms[i].y;
			coord.z = 0;
			vec_pushback(&data->graph.coords, &coord);
			++i;
		}
	else
		while (i < rooms)
		{
			coord.x = data->graph.rooms[i].x;
			coord.y = data->graph.rooms[i].y;
			coord.z = rand() % data->graph.z_scale;
			vec_pushback(&data->graph.coords, &coord);
			++i;
		}
}

static void		set_graph_center(t_data *data)
{
	t_int32	min_x;
	t_int32	min_y;
	t_int32	max_x;
	t_int32	max_y;
	size_t i;

	min_x = data->graph.rooms[0].x;
	min_y = data->graph.rooms[0].y;
	max_x = data->graph.rooms[0].x;
	max_y = data->graph.rooms[0].y;
	i = 0;
	while (++i < vec_size(data->graph.rooms))
	{
		if (data->graph.rooms[i].x > max_x)
			max_x = data->graph.rooms[i].x;
		if (data->graph.rooms[i].x < min_x)
			min_x = data->graph.rooms[i].x;
		if (data->graph.rooms[i].y > max_y)
			max_y = data->graph.rooms[i].y;
		if (data->graph.rooms[i].y < min_y)
			min_y = data->graph.rooms[i].y;
	}
	data->graph.x_center = max_x - (max_x - min_x) / 2;
	data->graph.y_center = max_y - (max_y - min_y) / 2;
}

void			some_configs(t_data *data)
{
	find_best_z_scale(data);
	set_coords(data);
	set_graph_center(data);
}