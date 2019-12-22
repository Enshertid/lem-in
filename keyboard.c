#include "vizu.h"


int key_press(int keycode, t_data *data)
{
	if (keycode == ESC)
		vizu_exit(data);
	else if (keycode == UP) {
		data->wnd.y_offset -= 10;
		data->graph.y_center -= 10;
	}
	else if (keycode == DOWN) {
		data->wnd.y_offset += 10;
		data->graph.y_center += 10;
	}
	else if (keycode == LEFT) {
		data->wnd.x_offset -= 10;
		data->graph.x_center -= 10;
	}
	else if (keycode == RIGHT) {
		data->wnd.x_offset += 10;
		data->graph.x_center += 10;
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
	if (ft_abs(data->wnd.angles.x) == 360)
		data->wnd.angles.x = 0;
	if (ft_abs(data->wnd.angles.y) == 360)
		data->wnd.angles.y = 0;
	if (ft_abs(data->wnd.angles.z) == 360)
		data->wnd.angles.z = 0;
	draw_map(data);
	return (1);
}