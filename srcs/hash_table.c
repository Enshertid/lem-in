/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 21:54:43 by ymanilow          #+#    #+#             */
/*   Updated: 2020/01/17 22:30:32 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash_table.h"

int								hash_search(t_hash_table *hash, t_room *room)
{

}

t_hash							*hash_create(int size, t_room *room)
{
	t_hash			*hash;

	hash = ft_memalloc(sizeof(t_hash) * size);
	hash->room = room;
	return(hash);
}

void							hash_add(t_hash *hash, t_room *room, int index)
{
	t_hash				*tmp;
	t_hash				*new;

	if (hash[index].room)
	{
		new = hash_create(1, room);
		tmp = &hash[index];
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		hash[index].room = room;
}

void							hash_free(t_hash_table *hash)
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
