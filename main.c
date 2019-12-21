#include "vizu.h"




void draw_map(t_data *data)
{
	ft_memset(data->wnd.img, 0, HEIGHT * data->wnd.size_line);
	t_point a;
	t_point b;
	a.red = (__WHITE >> 16) & 255;
	a.green = (__WHITE >> 8) & 255;
	a.blue = __WHITE & 255;
	b.red = (__WHITE >> 16) & 255;
	b.green = (__WHITE >> 8) & 255;
	b.blue = __WHITE & 255;
	for (size_t i = 0; i < vec_size(data->graph.rooms); ++i)
	{
		if (!data->graph.rooms[i].links)
			continue;
		for (size_t j = 0; j < vec_size(data->graph.rooms[i].links); ++j)
		{
			a.x = data->graph.rooms[i].x + data->wnd.x_offset;
			a.y = data->graph.rooms[i].y + data->wnd.y_offset;
			b.x = data->graph.rooms[i].links[j]->x + data->wnd.x_offset;
			b.y = data->graph.rooms[i].links[j]->y + data->wnd.y_offset;
			draw_line(&data->wnd, a, b);
		}
	}
	mlx_put_image_to_window(data->wnd.mlxptr, data->wnd.wndptr, data->wnd.imgptr, 0, 0);
}





int main(int argc, const char **argv)
{
	t_data	data;

	data = get_input(argv);
	draw_map(&data);

	mlx_hook(data.wnd.wndptr, 2, 1L << 0, key_press, &data);
	mlx_hook(data.wnd.wndptr, 17, 1L << 17, vizu_exit, &data);
	mlx_hook(data.wnd.wndptr, 4, 1L << 2, mouse_press, &data);
	mlx_hook(data.wnd.wndptr, 5, 1L << 3, mouse_release, &data);
	mlx_hook(data.wnd.wndptr, 6, 1L << 13, mouse_move, &data);
	mlx_loop_hook(data.wnd.mlxptr, animation, &data);
	mlx_loop(data.wnd.mlxptr);

	return (argc && !argc);
}













