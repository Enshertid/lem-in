/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 21:54:43 by ymanilow          #+#    #+#             */
/*   Updated: 2020/02/13 22:24:14 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "hash_table.h"

int							hash_index_create(int size, char *str)
{
	const char			*name;
	int					lenght;
	int					hash;

	name = str;
	hash = 0;
	lenght = (int)ft_strlen(name) + 1;
	while (--lenght > 0)
		hash += *name++ * ft_pow(31, lenght);
	if (hash < 0)
		hash *= -1;
	hash = hash % size;
	return (hash);
}

int							hash_check(t_hash_table *hash, int index,
																char *name)
{
	t_hash				*tmp;

	if (hash->hash_table[index].room)
	{
		tmp = &hash->hash_table[index];
		while (tmp)
		{
			if (ft_strequ(tmp->room->name, name))
				return (1);
			tmp = tmp->next;
		}
	}
	return (0);
}

t_room						*hash_search(t_hash_table *hash, int index,
																char *name)
{
	t_hash				*tmp;

	tmp = &hash->hash_table[index];
	while (tmp)
	{
		if (ft_strequ(tmp->room->name, name))
			return (tmp->room);
		tmp = tmp->next;
	}
	return (NULL);
}

void						hash_add(t_hash_table *hash, t_room *room)
{
	t_hash				*new;

	if (hash->hash_table[room->hash_index].room)
	{
		new = ft_memalloc(sizeof(t_hash));
		new->room = room;
		new->next = hash->hash_table[room->hash_index].next;
		hash->hash_table[room->hash_index].next = new;
	}
	else
		hash->hash_table[room->hash_index].room = room;
}
