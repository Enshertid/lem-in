/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_table.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 21:54:57 by ymanilow          #+#    #+#             */
/*   Updated: 2020/01/17 22:09:08 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#define HASH_SIZE 10000

#include "graph.h"

typedef struct					s_hash
{
	t_room						*room;
	struct s_hash				*next;
}								t_hash;

typedef struct					s_hash_table
{
	int							size;
	t_hash						*hash_table;
}								t_hash_table;

t_hash							*hash_create();
void							hash_add(t_hash *hash, t_room *room, int index);
void							hash_free(t_hash_table *hash);

#endif
