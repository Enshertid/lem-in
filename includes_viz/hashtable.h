/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <dbendu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 21:29:43 by dbendu            #+#    #+#             */
/*   Updated: 2020/02/14 02:16:03 by dbendu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHTABLE_H
# define HASHTABLE_H

# include "libft.h"
# include "tree.h"

typedef struct	s_map
{
	t_tree		**arr;
	size_t		size;
}				t_map;

t_map			map_create(size_t size);
void			map_destroy(t_map *map);
void			map_insert(t_map *map, void *key, void *value);
void			*map_find(t_map *map, void *key);

#endif
