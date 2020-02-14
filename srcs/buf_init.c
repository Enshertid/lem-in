/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buf_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 03:07:12 by ymanilow          #+#    #+#             */
/*   Updated: 2020/02/14 03:07:14 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_buf.h"

void			buf_init(int fd, size_t size)
{
	t_buf		**buf;

	buf = get_buf();
	if (size)
	{
		*buf = malloc(sizeof(t_buf) + size);
		(*buf)->size = size;
	}
	else
	{
		*buf = malloc(sizeof(t_buf) + DEFAULT_BUFSIZE);
		(*buf)->size = DEFAULT_BUFSIZE;
	}
	(*buf)->pos = 0;
	(*buf)->fd = fd;
	(*buf)->printed = 0;
	(*buf)->buf = (void*)*buf + sizeof(t_buf);
}
