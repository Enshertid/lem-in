/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 21:54:43 by ymanilow          #+#    #+#             */
/*   Updated: 2020/01/23 22:38:04 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "hash_table.h"

int						hash_index_create(int size, char *str)
{
	const char			*name;
	int					lenght;
	int					hash;

	name = str;
	hash = 0;
	lenght = (int)ft_strlen(name) + 1;
	if (lenght > 6)
		lenght = 6;
	while (--lenght > 0)
		hash += *name++ * ft_pow(31, lenght);
	if (hash < 0)
		hash *= -1;
	hash = hash % size;
	return (hash);
}

int						hash_check(t_hash_table *hash, int index, char *name)
{
	int					i;

	i = -1;
	while (++i < hash->hash_table[index].iter.i)
		if (ft_strequ(hash->hash_table[index].rooms[i]->name, name))
			return (1);
	return (0);
}

t_room						*hash_search(t_hash_table *hash, int index, char *name)
{
	int					i;

	i = -1;
	while (++i < hash->hash_table[index].iter.i)
		if (ft_strequ(hash->hash_table[index].rooms[i]->name, name))
			return (hash->hash_table[index].rooms[i]);
	return (NULL);
}

void						remalloc_hash_array(t_hash *hash)
{
	t_room		**new;
	int			i;

	hash->iter.col *= 2;
	new = ft_memalloc(sizeof(t_room*) * hash->iter.col);
	i = -1;
	while (++i < hash->iter.i)
		new[i] = hash->rooms[i];
	free(hash->rooms);
	hash->rooms = new;
}

void						hash_add(t_hash_table *hash, t_room *room)
{
	if (hash->hash_table[room->hash_index].iter.col)
	{
		if (hash->hash_table[room->hash_index].iter.i ==
						hash->hash_table[room->hash_index].iter.col)
			remalloc_hash_array(&hash->hash_table[room->hash_index]);
		hash->hash_table[room->hash_index].rooms[hash->hash_table[room->hash_index].iter.i++] = room;
	}
	else
	{
		hash->hash_table[room->hash_index].iter.col = HASH_ARRAY;
		hash->hash_table[room->hash_index].iter.i = 1;
		hash->hash_table[room->hash_index].rooms = ft_memalloc(sizeof(t_room*)
				* hash->hash_table[room->hash_index].iter.col);
		hash->hash_table[room->hash_index].rooms[0] = room;
	}
}
