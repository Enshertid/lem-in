/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 04:16:50 by ymanilow          #+#    #+#             */
/*   Updated: 2020/02/14 04:18:06 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*vec_increase(void **vec)
{
	size_t	new_size;
	void	*ptr;

	if (((size_t*)*vec)[-4] < 64)
		new_size = ((size_t*)*vec)[-4] + 16;
	else
		new_size = (size_t)(((size_t*)*vec)[-4] * 1.25);
	ptr = malloc(new_size * ((size_t*)*vec)[-2] + __INFO);
	ptr += __INFO;
	((size_t*)ptr)[-4] = ((size_t*)*vec)[-4];
	((size_t*)ptr)[-3] = new_size - ((size_t*)ptr)[-4];
	((size_t*)ptr)[-2] = ((size_t*)*vec)[-2];
	((size_t*)ptr)[-1] = ((size_t*)*vec)[-1];
	ft_memcpy(ptr, *vec, ((size_t*)ptr)[-4] * ((size_t*)ptr)[-2]);
	free(*vec - __INFO);
	return (ptr);
}

void		vec_pushback(void *ptr, void *elem)
{
	void	**vec;
	size_t	*help;

	vec = (void**)ptr;
	if (!((size_t*)*vec)[-3])
		*vec = vec_increase(vec);
	help = (size_t*)*vec;
	ft_memcpy(*vec + help[-4] * help[-2], elem, help[-2]);
	++help[-4];
	--help[-3];
}

void		vec_delelem(void *vecptr, size_t pos)
{
	void *vec;

	if (!vecptr || !vecptr)
		return ;
	vec = *(void**)vecptr;
	if (((size_t*)vec)[-4] <= pos)
		return ;
	ft_memcpy(vec + pos * ((size_t*)vec)[-2],
			vec + (pos + 1) * ((size_t*)vec)[-2],
			(((size_t*)vec)[-4] - pos - 1) * ((size_t*)vec)[-2]);
	--((size_t*)vec)[-4];
	++((size_t*)vec)[-3];
}
