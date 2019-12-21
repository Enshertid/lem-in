#include "vizu.h"

int key_press(int keycode, t_data *data)
{
	if (keycode == ESC)
		vizu_exit(data);
	else if (keycode == UP)
		--data->wnd.y_offset;
	else if (keycode == DOWN)
		++data->wnd.y_offset;
	else if (keycode == LEFT)
		--data->wnd.x_offset;
	else if (keycode == RIGHT)
		++data->wnd.x_offset;
//	else if (keycode == )	// rotate!
	draw_map(data);
	return (1);
}