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

t_data				get_input(const char **argv)
{
	t_data	data;

	data.flags = get_flags(argv);
	data.wnd = wnd_init();
	data.graph = get_graph(argv);
	some_configs(&data);
	return (data);
}


























