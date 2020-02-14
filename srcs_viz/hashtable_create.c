/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable_create.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <dbendu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 21:30:01 by dbendu            #+#    #+#             */
/*   Updated: 2020/02/13 23:51:47 by dbendu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtable.h"

t_map			map_create(size_t size)
{
	t_map		map;

	map.size = size;
	map.arr = malloc(sizeof(void*) * size);
	ft_memset(map.arr, 0, sizeof(t_tree*) * size);
	return (map);
}
