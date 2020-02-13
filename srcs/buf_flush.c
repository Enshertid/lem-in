#include "ft_buf.h"

void			buf_flush(void)
{
	t_buf		*buf;

	buf = *get_buf();
	if (buf->pos)
	{
		write(buf->fd, buf->buf, buf->pos);
		buf->printed += buf->pos;
		buf->pos = 0;
	}
}
