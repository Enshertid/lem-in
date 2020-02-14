/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 04:16:34 by ymanilow          #+#    #+#             */
/*   Updated: 2020/02/14 04:17:50 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*vec_init(size_t rows, size_t elems, size_t type_size)
{
	void	*vec;
	void	**vec_ptr;
	size_t	iter;

	if (!rows)
	{
		vec = malloc(type_size * elems + __INFO);
		((size_t*)vec)[0] = 0;
		((size_t*)vec)[1] = elems;
		((size_t*)vec)[2] = type_size;
		((size_t*)vec)[3] = 0;
		return (vec + __INFO);
	}
	vec_ptr = (void**)malloc(rows * sizeof(void*) + sizeof(size_t));
	((size_t*)(vec_ptr += 1))[-1] = rows;
	iter = 0;
	while (iter < rows)
	{
		((size_t*)vec_ptr)[iter] = (size_t)vec_init(0, elems, type_size);
		((size_t**)vec_ptr)[iter][-1] = rows;
		++iter;
	}
	return (vec_ptr);
}

void	vec_clear(void *ptr)
{
	void	**vec;
	size_t	iter;

	if (!*(void**)ptr)
		return ;
	vec = (void**)ptr;
	if (!((size_t*)*vec)[-1])
	{
		free(*vec - __INFO);
		*vec = NULL;
	}
	else
	{
		iter = 0;
		while (iter < ((size_t*)*vec)[-1])
		{
			free(((size_t**)*vec)[iter] - __INFO / sizeof(size_t));
			++iter;
		}
		free(*vec - sizeof(size_t));
		*vec = NULL;
	}
}

void	vec_addrow(void *ptr, size_t elems)
{
	void	**vec;
	size_t	**new_vec;
	size_t	i;

	vec = *(void**)ptr;
	new_vec = (size_t**)malloc(sizeof(void*) * (((size_t*)*vec)[-1] + 1) +
								sizeof(size_t));
	new_vec += 1;
	((size_t*)new_vec)[-1] = ((size_t*)*vec)[-1];
	i = 0;
	while (i < ((size_t*)new_vec)[-1])
	{
		new_vec[i] = ((size_t**)vec)[i];
		new_vec[i][-1] = ((size_t*)new_vec)[-1] + 1;
		++i;
	}
	new_vec[((size_t*)new_vec)[-1]] = vec_init(0, elems, ((size_t*)*vec)[-2]);
	++((size_t*)new_vec)[-1];
	free(*(size_t**)ptr - 1);
	*(void**)ptr = new_vec;
}

void	vec_cut(void *ptr)
{
	size_t *new_vec;
	size_t *vec;
	size_t new_size;

	if (!ptr || !((size_t**)*(void**)ptr)[-3])
		return ;
	vec = *(void**)ptr;
	new_size = vec[-4] * vec[-2] + __INFO;
	new_vec = (size_t*)malloc(new_size);
	new_vec += __INFO / sizeof(size_t);
	new_vec[-4] = vec[-4];
	new_vec[-3] = 0;
	new_vec[-2] = vec[-2];
	new_vec[-1] = vec[-1];
	ft_memcpy(new_vec, vec, vec[-4] * vec[-2]);
	free(vec - __INFO / sizeof(size_t));
	*(void**)ptr = new_vec;
}

void	*vec_cp(void *ptr)
{
	size_t	*vec;
	size_t	temp;
	size_t	iter;

	if (!((size_t*)ptr)[-1])
	{
		vec = (size_t*)malloc(vec_tpsz(ptr) * vec_size(ptr) + __INFO);
		ft_memcpy(vec, ptr - __INFO, __INFO + vec_tpsz(ptr) * vec_size(ptr));
		vec[1] = 0;
		return (vec + 4);
	}
	vec = (size_t*)malloc(vec_rows(ptr) * sizeof(void*) + sizeof(size_t));
	vec += 1;
	temp = vec_rows(ptr);
	iter = 0;
	while (iter < vec_rows(ptr))
	{
		((size_t**)ptr)[iter][-1] = 0;
		((size_t**)vec)[iter] = vec_cp(((size_t**)ptr)[iter]);
		((size_t**)ptr)[iter][-1] = temp;
		++iter;
	}
	vec[-1] = vec_rows(ptr);
	return (vec);
}
