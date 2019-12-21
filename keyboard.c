#include "vizu.h"


int key_press(int keycode, t_data *data)
{
	if (keycode == ESC)
		vizu_exit(data);
	else if (keycode == UP) {
		--data->wnd.y_offset;
		--data->graph.y_center;
	}
	else if (keycode == DOWN) {
		++data->wnd.y_offset;
		++data->graph.y_center;
	}
	else if (keycode == LEFT) {
		--data->wnd.x_offset;
		--data->graph.x_center;
	}
	else if (keycode == RIGHT) {
		++data->wnd.x_offset;
		++data->graph.x_center;
	}
	else if (keycode == D)
		data->wnd.angles.y += 3;
	else if (keycode == A)
		data->wnd.angles.y -= 3;
	else if (keycode == W)
		data->wnd.angles.x += 3;
	else if (keycode == S)
		data->wnd.angles.x -= 3;
	else if (keycode == Q)
		data->wnd.angles.z += 3;
	else if (keycode == E)
		data->wnd.angles.z -= 3;
	draw_map(data);
	return (1);
}