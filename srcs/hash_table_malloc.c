/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_table_malloc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 13:35:58 by ymanilow          #+#    #+#             */
/*   Updated: 2020/02/12 15:31:13 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash_table.h"

void						hash_free(t_hash_table *hash)
{
	t_hash				*tmp;
	t_hash				*tmp_1;
	int					i;

	i = -1;
	while (++i < hash->size)
	{
		if (hash->hash_table[i].next)
		{
			tmp = hash->hash_table[i].next;
			tmp_1 = tmp;
			while (tmp)
			{
				tmp = tmp->next;
				free(tmp_1);
				tmp_1 = tmp;
			}
		}
	}
	free(hash->hash_table);
}

t_hash						*hash_array_create(int size)
{
	t_hash			*hash;

	hash = ft_memalloc(sizeof(t_hash) * size);
	return (hash);
}
