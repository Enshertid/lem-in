#include "ft_buf.h"

char		*buf_get(size_t *pos)
{
	t_buf	**buf;

	buf = get_buf();
	if (*buf)
	{
		*pos = (*buf)->pos;
		return ((*buf)->buf);
	}
	else
		return (NULL);
}
