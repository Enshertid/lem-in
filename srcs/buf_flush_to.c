/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buf_flush_to.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 03:07:38 by ymanilow          #+#    #+#             */
/*   Updated: 2020/02/14 03:07:40 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
