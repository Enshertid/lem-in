/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_table_malloc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 13:35:58 by ymanilow          #+#    #+#             */
/*   Updated: 2020/01/23 22:30:57 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash_table.h"

void						hash_free(t_hash_table *hash)
{
	int					i;

	i = -1;
	while(++i < hash->size)
	{
		if (hash->hash_table[i].iter.col)
			free(hash->hash_table[i].rooms);
	}
	free(hash->hash_table);
}

t_hash						*hash_array_create(int size)
{
	t_hash			*hash;

	hash = ft_memalloc(sizeof(t_hash) * size);
	return(hash);
}
