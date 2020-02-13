/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable_insert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <dbendu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 21:30:12 by dbendu            #+#    #+#             */
/*   Updated: 2020/02/13 21:42:24 by dbendu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtable.h"
#include "hashtable_private.h"

void				map_insert(t_map *map, void *key, void *value)
{
	size_t			index;

	index = hash_code(key) % map->size;
	if (!map->arr[index])
		map->arr[index] = tree_create();
	tree_insert(map->arr[index], key, value);
}
