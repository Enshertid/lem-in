#include "ft_buf.h"

void			buf_add_str(const char *str)
{
	t_buf		*buf;
	size_t		strlen;

	buf = *get_buf();
	strlen = ft_strlen(str);
	if (strlen < buf->size - buf->pos)
	{
		ft_memcpy(buf->buf + buf->pos, str, strlen);
		buf->pos += strlen;
	}
	else
	{
		buf_flush();
		if (strlen > buf->size * 0.75)
		{
			write(buf->fd, str, strlen);
			buf->printed += strlen;
		}
		else
		{
			ft_memcpy(buf->buf, str, strlen);
			buf->pos += strlen;
		}
	}
}
