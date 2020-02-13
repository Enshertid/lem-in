#include "ft_buf.h"

t_buf				**get_buf(void)
{
	static t_buf	*buf = NULL;

	return (&buf);
}
