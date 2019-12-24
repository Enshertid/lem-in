#include "vizu.h"


void	rotate_map(t_data *data) {
	size_t i;
	size_t rooms;
	t_int32 x;
	t_int32 y;
	t_int32 z;

	rooms = vec_size(data->graph.rooms);
	i = 0;
	while (i < rooms) {
		x = data->basic_coords[i].x;
		y = data->basic_coords[i].y;
		z = data->basic_coords[i].z;
		data->graph.rooms[i].y = y * cos(data->wnd.angles.x * 3.14 / 180) + z * sin(data->wnd.angles.x * 3.14 / 180);
		data->graph.rooms[i].z = -y * sin(data->wnd.angles.x * 3.14 / 180) + z * cos(data->wnd.angles.x * 3.14 / 180);
		y = data->graph.rooms[i].y;
		z = data->graph.rooms[i].z;
		data->graph.rooms[i].x = x * cos(data->wnd.angles.y * 3.14 / 180) + z * sin(data->wnd.angles.y * 3.14 / 180);
		data->graph.rooms[i].z = -x * sin(data->wnd.angles.y * 3.14 / 180) + z * cos(data->wnd.angles.y * 3.14 / 180);
		x = data->graph.rooms[i].x;
		z = data->graph.rooms[i].z;
		data->graph.rooms[i].x = x * cos(data->wnd.angles.z * 3.14 / 180) - y * sin(data->wnd.angles.z * 3.14 / 180);
		data->graph.rooms[i].y = x * sin(data->wnd.angles.z * 3.14 / 180) + y * cos(data->wnd.angles.z * 3.14 / 180);
		data->graph.rooms[i].x += data->wnd.x_offset;
		data->graph.rooms[i].y += data->wnd.y_offset;
		++i;
	}
}

static void set_color(t_point *point, int color)
{
	point->red = (color >> 16) & 255;
	point->green = (color >> 8) & 255;
	point->blue = color & 255;
}

static void ant_put(t_data *data, int x, int y)
{
	mlx_put_image_to_window(data->wnd.mlxptr, data->wnd.wndptr, data->wnd.ant_img.imgptr, x - 5, y - 8);
}

void	draw_map(t_data *data)
{
	ft_memset(data->wnd.graph_img.img, 0, HEIGHT * data->wnd.graph_img.size_line);
	rotate_map(data);
	t_point a;
	t_point b;
	set_color(&b, __WHITE);
	for (size_t i = 0; i < vec_size(data->graph.rooms); ++i)
		data->graph.rooms[i].is_draw = TRUE;
	for (size_t i = 0; i < vec_size(data->graph.rooms); ++i)
	{
		if (!data->graph.rooms[i].links)
			continue;
		if (i == 0)
			set_color(&a, 255 << 8);
		else if (i == 1)
			set_color(&a, 255 << 16);
		else
			set_color(&a, __WHITE);
		a.x = data->graph.rooms[i].x;
		a.y = data->graph.rooms[i].y;
		for (int j = vec_size(data->graph.rooms[i].links) - 1; j >= 0; --j)
		{
			if (!data->graph.rooms[i].links[j]->is_draw)
				continue;
			b.x = data->graph.rooms[i].links[j]->x;
			b.y = data->graph.rooms[i].links[j]->y;
			draw_line(&data->wnd.graph_img, a, b);
		}
		data->graph.rooms[i].is_draw = FALSE;
	}
	mlx_put_image_to_window(data->wnd.mlxptr, data->wnd.wndptr, data->wnd.graph_img.imgptr, 0, 0);
	if (data->graph.ants)
		ant_put(data, data->graph.rooms[0].x, data->graph.rooms[0].y);
	mlx_pixel_put(data->wnd.mlxptr,  data->wnd.wndptr, data->graph.x_center, data->graph.y_center, 255 << 16);
	mlx_pixel_put(data->wnd.mlxptr,  data->wnd.wndptr, data->wnd.x_offset, data->wnd.y_offset, 255 << 8);
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











