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
	else if (button == WHEEL_UP)
	{
		for (size_t i = 0; i < vec_size(data->basic_coords); ++i)
		{
			if (data->basic_coords[i].x + data->wnd.x_offset > data->graph.x_center)
				data->basic_coords[i].x += 3;
			else
				data->basic_coords[i].x -= 3;
			if (data->basic_coords[i].y + data->wnd.y_offset > data->graph.y_center)
				data->basic_coords[i].y += 3;
			else
				data->basic_coords[i].y -= 3;
			data->basic_coords[i].z += data->basic_coords[i].z > 0 ? 3 : -3;
		}
		draw_map(data);
	}
	else if (button == WHEEL_DOWN)
	{
		for (size_t i = 0; i < vec_size(data->graph.rooms); ++i)
		{
			if (data->basic_coords[i].x + data->wnd.x_offset > data->graph.x_center)
				--data->basic_coords[i].x;
			else
				++data->basic_coords[i].x;
			if (data->basic_coords[i].y + data->wnd.y_offset > data->graph.y_center)
				--data->basic_coords[i].y;
			else
				++data->basic_coords[i].y;
			data->basic_coords[i].z += data->basic_coords[i].z > 0 ? -3 : 3;
		}
		draw_map(data);
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
		data->graph.x_center += x - data->wnd.mouse.x;
		data->graph.y_center += y - data->wnd.mouse.y;
		data->wnd.mouse.x = x;
		data->wnd.mouse.y = y;
	}
	else
		return (1);
	draw_map(data);
	return (1);
}