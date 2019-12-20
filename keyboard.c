#include "vizu.h"

int key_press(int keycode, t_wnd *wnd)
{
	if (keycode == ESC)
		vizu_exit(wnd);

	return (1);
}
