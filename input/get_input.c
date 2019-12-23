#include "vizu.h"

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


























