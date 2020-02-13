#include "ft_buf.h"

void			buf_flush_to(int fd)
{
	t_buf		*buf;

	buf = *get_buf();
	if (buf->pos)
	{
		write(fd, buf->buf, buf->pos);
		buf->printed += buf->pos;
		buf->pos = 0;
	}
}
