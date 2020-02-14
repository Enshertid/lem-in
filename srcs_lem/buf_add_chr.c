/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buf_add_chr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 03:07:41 by ymanilow          #+#    #+#             */
/*   Updated: 2020/02/14 03:07:43 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_buf.h"

void			buf_add_chr(char chr, size_t times)
{
	t_buf		*buf;

	buf = *get_buf();
	if (times <= buf->size - buf->pos)
	{
		ft_memset(buf->buf + buf->pos, chr, times);
		buf->pos += times;
	}
	else
	{
		buf_flush();
		ft_memset(buf->buf, chr, ft_min(times, buf->size));
		while (times)
		{
			buf_flush();
			buf->pos = ft_min(times, buf->size);
			times -= buf->pos;
		}
	}
}
