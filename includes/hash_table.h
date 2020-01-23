/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_table.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 21:54:57 by ymanilow          #+#    #+#             */
/*   Updated: 2020/01/23 22:03:03 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#define HASH_SIZE 10000
#define HASH_ARRAY 2

#include "graph.h"

typedef struct					s_hash
{
	t_iters						iter;
	t_room						**rooms;
}								t_hash;

typedef struct					s_hash_table
{
	int							size;
	t_hash						*hash_table;
}								t_hash_table;

t_room							*hash_search(t_hash_table *hash,
												int index, char *name);
int								hash_index_create(int size, char *str);
int								hash_check(t_hash_table *hash,
												int index, char *name);
void							hash_add(t_hash_table *hash, t_room *room);

t_hash							*hash_array_create(int size);
void							hash_free(t_hash_table *hash);

#endif
