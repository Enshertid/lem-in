/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_store.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 14:59:43 by ymanilow          #+#    #+#             */
/*   Updated: 2019/12/23 19:43:19 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static	t_void		**ft_storage()
{
	static t_void		*storage;

	return(&storage);
}

void					*ft_malloc_store(size_t size)
{
	void			*data;
	t_void			**storage;
	t_void			*tmp;

	if (!(storage = ft_storage()))
		return (NULL);
	if (!(data = ft_memalloc(size)))
		ft_error("can't allocate memory in storage's data\n", 500);
	if (*storage)
	{
		tmp = ft_memalloc(sizeof(t_void));
		tmp->data = data;
		tmp->next = (*storage);
		(*storage) = tmp;
	}
	else if (!(*storage))
	{
		*storage = ft_memalloc(sizeof(t_void));
		(*storage)->data = data;
		(*storage)->next = NULL;
	}
	return (data);
}

void 					ft_free_storage()
{
	t_void			*tmp;
	t_void			**storage;

	storage = ft_storage();
	if (!(*storage))
		ft_error("you can't free unused memory\n", 500);
	tmp = *storage;
	while (tmp)
	{
		tmp = tmp->next;
		free((*storage)->data);
		(*storage)->data = NULL;
		(*storage)->next = NULL;
		free(*storage);
		(*storage) = tmp;
	}
	free(*storage);

}
