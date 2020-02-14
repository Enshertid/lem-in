/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable_destroy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 21:30:04 by dbendu            #+#    #+#             */
/*   Updated: 2020/02/04 22:41:05 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtable.h"

void			map_destroy(t_map *map)
{
	size_t		iter;

	iter = 0;
	while (iter < map->size)
	{
		tree_destroy(map->arr[iter]);
		++iter;
	}
}
