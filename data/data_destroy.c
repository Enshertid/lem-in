#include "data.h"

void			data_destroy(t_data *data)
{
	wnd_destroy(&data->wnd);
	graph_destroy(&data->graph);
	animation_destroy(&data->animation);
	UNUSED_VAR(data);
}
