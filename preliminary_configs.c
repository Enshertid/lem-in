#include "vizu.h"

static void		find_best_z_scale(t_data *data)
{
	size_t	x_sum;
	size_t	y_sum;
	size_t	i;

	if (!(data->flags & FLAG_Z))
		return ;
	x_sum = 0;
	y_sum = 0;
	i = 0;
	while (i < vec_size(data->graph.rooms))
	{
		x_sum += data->graph.rooms[i].x;
		y_sum += data->graph.rooms[i].y;
		++i;
	}
	if (x_sum > y_sum)
		data->graph.z_scale = ft_max(x_sum, y_sum) / vec_size(data->graph.rooms);
	else
		data->graph.z_scale = ft_max(y_sum, x_sum) / vec_size(data->graph.rooms);
	printf("%d\n", data->graph.z_scale);
}

static void		set_coords(t_data *data)
{
	size_t		i;
	size_t		rooms;
	t_coord		coord;
	time_t 		t;

	srand((unsigned)time(&t));
	rooms = vec_size(data->graph.rooms);
	data->basic_coords = vec_init(0, rooms, sizeof (t_coord));
	i = 0;
	if (!(data->flags & FLAG_Z))
		while (i < rooms)
		{
			coord.x = data->graph.rooms[i].x;
			coord.y = data->graph.rooms[i].y;
			coord.z = 0;
			vec_pushback(&data->basic_coords, &coord);
			++i;
		}
	else
		while (i < rooms)
		{
			coord.x = data->graph.rooms[i].x;
			coord.y = data->graph.rooms[i].y;
			coord.z = rand() % data->graph.z_scale;
			if ((size_t)coord.z > data->graph.z_scale / 2)
				coord.z = -coord.z;
			vec_pushback(&data->basic_coords, &coord);
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