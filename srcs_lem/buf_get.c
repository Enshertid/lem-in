/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buf_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 03:07:32 by ymanilow          #+#    #+#             */
/*   Updated: 2020/02/14 03:07:34 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
