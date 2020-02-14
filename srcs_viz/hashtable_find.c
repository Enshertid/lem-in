/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable_find.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 21:30:07 by dbendu            #+#    #+#             */
/*   Updated: 2020/02/14 04:26:49 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtable.h"
#include "hashtable_private.h"

void			*map_find(t_map *map, void *key)
{
	uint64_t	hash;
	size_t		index;

	hash = hash_code(key);
	index = hash % map->size;
	if (!map || !map->arr[index])
		return (NULL);
	else
		return (tree_find(map->arr[index], key));
}
