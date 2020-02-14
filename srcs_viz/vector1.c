/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 04:16:16 by ymanilow          #+#    #+#             */
/*   Updated: 2020/02/14 04:16:21 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	vec_size(const void *vec)
{
	return (((size_t*)vec)[-4]);
}

size_t	vec_free(const void *vec)
{
	return (((size_t*)vec)[-3]);
}

size_t	vec_tpsz(const void *vec)
{
	return (((size_t*)vec)[-2]);
}

size_t	vec_rows(const void *vec)
{
	return (((size_t*)vec)[-1]);
}

void	vec_set_size(void *vec, size_t size)
{
	size_t cur_size;
	size_t max_size;

	max_size = ((size_t*)vec)[-4] + ((size_t*)vec)[-3];
	if (max_size > size)
		return ;
	cur_size = ((size_t*)vec)[-4];
	((size_t*)vec)[-4] = size;
	if (cur_size < size)
		((size_t*)vec)[-3] -= size;
	else
		((size_t*)vec)[-3] += size;
}
