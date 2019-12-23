#include "vizu.h"

int		vizu_exit(t_data *data)
{
	size_t room;

	room = 0;
	while (room < vec_size(data->graph.rooms))
	{
		if (data->graph.rooms[room].links)
			vec_clear(&data->graph.rooms[room].links);
		free(data->graph.rooms[room].name);
		++room;
	}
	mlx_destroy_image(data->wnd.mlxptr, data->wnd.graph_img.imgptr);
	mlx_destroy_window(data->wnd.mlxptr, data->wnd.wndptr);
	exit(0);
	return (0);
}