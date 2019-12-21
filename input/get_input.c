#include "vizu.h"

static t_wnd		wnd_init(void)
{
	t_wnd	wnd;

	ft_memset(&wnd, 0, sizeof(t_wnd));
	wnd.mlxptr = mlx_init();
	wnd.wndptr = mlx_new_window(wnd.mlxptr, WIDTH, HEIGHT, "lem-in vizualizer");
	wnd.imgptr = mlx_new_image(wnd.mlxptr, WIDTH, HEIGHT);
	wnd.img = mlx_get_data_addr(wnd.imgptr, &wnd.bytes, &wnd.size_line,
								&wnd.endian);
	wnd.bytes /= 8;
	wnd.x_offset = 0;
	wnd.y_offset = 0;
	return (wnd);
}

static t_uint64		get_flags(const char **argv)
{
	t_uint64 flags;

	flags = 0;
	while (*++argv)
	{
		if (**argv != '-')
			continue;
		while (*(++*argv))
		{
			if (**argv == 'z')
				flags |= FLAG_Z;
		}
	}
	return (flags);
}

static void			some_configs(t_data *data)
{
	size_t i;
	t_int32	min_x;
	t_int32	min_y;
	t_int32	max_x;
	t_int32	max_y;

	srand(time(0));
	i = 0;
	while (i < vec_size(data->graph.rooms))
	{
		if (data->flags & FLAG_Z)
			data->graph.rooms[i].z = rand() % 1000;
		else
			data->graph.rooms[i].z = 0;
		++i;
	}
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
	data->graph.x_center = (max_x - min_x) / 2;
	data->graph.y_center = (max_y - min_y) / 2;
}

t_data				get_input(const char **argv)
{
	t_data	data;

	data.flags = get_flags(argv);
	data.wnd = wnd_init();
	data.graph = get_graph(argv);
	some_configs(&data);
	return (data);
}



























