#include "vizu.h"

int		mouse_press(int button, int x, int y, t_data *data)
{
	if (x < 0 || y < 0 || x > MAX_X || y > MAX_Y)
		return (0);
	if (button == LEFT_BUTTON)
	{
		data->wnd.mouse.left = TRUE;
		data->wnd.mouse.x = x;
		data->wnd.mouse.y = y;
	}
	return (1);
}

int		mouse_release(int button, int x, int y, t_data *data)
{
	if (button == LEFT_BUTTON)
		data->wnd.mouse.left = FALSE;
	return (x | y);
}

int		mouse_move(int x, int y, t_data *data)
{
	if (data->wnd.mouse.left)
	{
		data->wnd.x_offset += x - data->wnd.mouse.x;
		data->wnd.y_offset += y - data->wnd.mouse.y;
		data->wnd.mouse.x = x;
		data->wnd.mouse.y = y;
		data->graph.x_center += (x - data->wnd.mouse.x);
		data->graph.y_center += (y - data->wnd.mouse.y);
	}
	else
		return (1);
	draw_map(data);
	return (1);
}