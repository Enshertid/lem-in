#include "vizu.h"

static void draw_line1(t_image *img, int x1, int y1, int x2, int y2)
{
	t_point a = {x1, y1, 0, 255, 0, 0};
	t_point b = {x2, y2, 0, 255, 0, 0};
	draw_line(img, a, b);
}

static void	draw_ant(t_image *img)
{
	draw_line1(img, 2, 0, 2, 1);
	draw_line1(img, 3, 2, 3, 2);
	draw_line1(img, 8, 0, 8, 1);
	draw_line1(img, 7, 2, 7, 2);
	draw_line1(img, 4, 3, 4, 5);
	draw_line1(img, 5, 3, 5, 11);
	draw_line1(img, 6, 3, 6, 5);
	draw_line1(img, 0, 4, 3, 7);
	draw_line1(img, 0, 8, 3, 8);
	draw_line1(img, 0, 12, 3, 9);
	draw_line1(img, 10, 4, 7, 7);
	draw_line1(img, 7, 8, 10, 8);
	draw_line1(img, 7, 9, 10, 12);
	draw_line1(img, 4, 11, 4, 15);
	draw_line1(img, 6, 11, 6, 15);
	draw_line1(img, 5, 15, 5, 15);
}

static t_wnd		wnd_init(void)
{
	t_wnd	wnd;

	ft_memset(&wnd, 0, sizeof(t_wnd));
	wnd.mlxptr = mlx_init();
	wnd.wndptr = mlx_new_window(wnd.mlxptr, WIDTH, HEIGHT, "lem-in vizualizer");
	wnd.graph_img.imgptr = mlx_new_image(wnd.mlxptr, WIDTH, HEIGHT);
	wnd.graph_img.img = mlx_get_data_addr(wnd.graph_img.imgptr, &wnd.graph_img.bytes, &wnd.graph_img.size_line,
								&wnd.graph_img.endian);
	wnd.graph_img.bytes /= 8;
	wnd.x_offset = 0;
	wnd.y_offset = 0;
	wnd.ant_img.imgptr = mlx_new_image(wnd.mlxptr, 11, 16);
	wnd.ant_img.img = mlx_get_data_addr(wnd.ant_img.imgptr, &wnd.ant_img.bytes, &wnd.ant_img.size_line,
										&wnd.ant_img.endian);
	wnd.ant_img.bytes /= 8;
	draw_ant(&wnd.ant_img);
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

t_data				get_input(const char **argv)
{
	t_data	data;

	ft_memset(&data, 0, sizeof(t_data));
	data.flags = get_flags(argv);
	data.wnd = wnd_init();
	data.graph = get_graph(argv);
	some_configs(&data);
	return (data);
}


























