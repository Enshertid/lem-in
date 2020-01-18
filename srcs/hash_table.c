/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 21:54:43 by ymanilow          #+#    #+#             */
/*   Updated: 2020/01/18 21:54:45 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash_table.h"

int							hash_check(t_hash_table *hash, int index, char *name)
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


int						hash_index_create(int size, char *str)
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

t_hash						*hash_array_create(int size)
{
	t_hash			*hash;

	hash = ft_memalloc(sizeof(t_hash) * size);
	return(hash);
}

void						hash_add(t_hash *hash, t_room *room)
{
	t_hash				*tmp;
	t_hash				*new;

	if (hash[room->hash_index].room)
	{
		new = ft_memalloc(sizeof(t_hash));
		new->room = room;
		tmp = hash[room->hash_index].next;
		if (!tmp)
			hash[room->hash_index].next = new;
		else
		{
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = new;
		}
	}
	else
	{
//		printf("%s\n\n\n", room->name);
		hash[room->hash_index].room = room;
	}
}

t_room						*hash_search(t_hash_table *hash, int index, char *name)
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
