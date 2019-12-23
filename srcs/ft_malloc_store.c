/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_store.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 14:59:43 by ymanilow          #+#    #+#             */
/*   Updated: 2019/12/23 18:21:29 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static	t_void		**ft_storage()
{
	static t_void		*storage;

	return(&storage);
}


void 					ft_lise_malloc_add(t_void **head, t_void **new)
{
	t_void			*tmp;

	if (*head && new)
	{
		tmp = *head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = *new;
	}
}

t_void					**ft_list_malloc_new(void *new, size_t size)
{
	t_void			**new_list;

	if (!(new_list = ft_memalloc(sizeof(t_void) + size)))
		ft_error("can't allocate memory in storage\n", 500);
	else
	{
		(*new_list)->data = new;
		(*new_list)->next = NULL;
	}
	return (new_list);
}

void					*ft_malloc_store(size_t size)
{
	void			*data;
	t_void			**storage;

	storage = ft_storage();
	if (!(data = ft_memalloc(size)))
		ft_error("can't allocate memory in storage's data\n", 500);
	if (storage)
		ft_lise_malloc_add(storage, ft_list_malloc_new(data, size));
	else if (!storage)
		storage = ft_list_malloc_new(data, size);
	return (data);
}

void 					ft_free_storage()
{
	t_void			*tmp;
	t_void			**storage;

	storage = ft_storage();
	if (!storage)
		ft_error("you can't free unused memory\n", 500);
	tmp = *storage;
	while (tmp)
	{
		tmp = tmp->next;
		free((*storage)->data);
		(*storage)->data = NULL;
		(*storage)->next = NULL;
		(*storage) = tmp;
	}
	free(storage);
}
