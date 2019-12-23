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
		data->graph.rooms[i].x = data->graph.coords[i].x;
		data->graph.rooms[i].y = data->graph.coords[i].y;
		data->graph.rooms[i].z = data->graph.coords[i].z;
	}
	for (size_t i = 0; i < vec_size(data->graph.rooms); ++i)
	{
		if (!data->graph.rooms[i].links)
			continue;
		a.x = data->graph.rooms[i].x;
		a.y = data->graph.rooms[i].y;
		a.z = data->graph.rooms[i].z;
		int x = a.x;
		int y = a.y;
		int z = a.z;
		a.y = y * cos(data->wnd.angles.x * 3.14 / 180) + z * sin(data->wnd.angles.x * 3.14 / 180);
		a.z = -y * sin(data->wnd.angles.x * 3.14 / 180) + z * cos(data->wnd.angles.x * 3.14 / 180);
		x = a.x;
		y = a.y;
		z = a.z;
		a.x = x * cos(data->wnd.angles.y * 3.14 / 180) + z * sin(data->wnd.angles.y * 3.14 / 180);
		a.z = -x * sin(data->wnd.angles.y * 3.14 / 180) + z * cos(data->wnd.angles.y * 3.14 / 180);
		x = a.x;
		y = a.y;
		z = a.z;
		a.x = x * cos(data->wnd.angles.z * 3.14 / 180) - y * sin(data->wnd.angles.z * 3.14 / 180);
		a.y = x * sin(data->wnd.angles.z * 3.14 / 180) + y * cos(data->wnd.angles.z * 3.14 / 180);
		a.x += data->wnd.x_offset;
		a.y += data->wnd.y_offset;
		printf("%s\n", data->graph.rooms[i].name);
		for (size_t j = 0; j < vec_size(data->graph.rooms[i].links); ++j)
		{
			b.x = data->graph.rooms[i].links[j]->x;
			b.y = data->graph.rooms[i].links[j]->y;
			b.z = data->graph.rooms[i].links[j]->z;
			x = b.x;
			y = b.y;
			z = b.z;
			b.y = y * cos(data->wnd.angles.x * 3.14 / 180) + z * sin(data->wnd.angles.x * 3.14 / 180);
			b.z = -y * sin(data->wnd.angles.x * 3.14 / 180) + z * cos(data->wnd.angles.x * 3.14 / 180);
			x = b.x;
			y = b.y;
			z = b.z;
			b.x = x * cos(data->wnd.angles.y * 3.14 / 180) + z * sin(data->wnd.angles.y * 3.14 / 180);
			b.z = -x * sin(data->wnd.angles.y * 3.14 / 180) + z * cos(data->wnd.angles.y * 3.14 / 180);
			x = b.x;
			y = b.y;
			z = b.z;
			b.x = x * cos(data->wnd.angles.z * 3.14 / 180) - y * sin(data->wnd.angles.z * 3.14 / 180);
			b.y = x * sin(data->wnd.angles.z * 3.14 / 180) + y * cos(data->wnd.angles.z * 3.14 / 180);
			b.x += data->wnd.x_offset;
			b.y += data->wnd.y_offset;
			printf("\t%d  --  %d\n", b.x, b.y);
			draw_line(&data->wnd, a, b);
		}
	}
	mlx_put_image_to_window(data->wnd.mlxptr, data->wnd.wndptr, data->wnd.imgptr, 0, 0);
}





int main(int argc, const char **argv)
{
	t_data	data;

	data = get_input(argv);
	size_t i;
	for (i = 0; i < vec_size(data.graph.rooms); ++i)
		if (ft_strequ(data.graph.rooms[i].name, "First_Internship"))
			break;
	printf("%d  --  %d -- %d\n", data.graph.rooms[i].x, data.graph.rooms[i].y, data.graph.rooms[i].z);
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












