/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_table.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 21:54:57 by ymanilow          #+#    #+#             */
/*   Updated: 2020/01/18 20:10:15 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#define HASH_SIZE 10

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

int								hash_index_create(int size, char *str);
t_hash							*hash_array_create(int size);
void							hash_add(t_hash *hash, t_room *room);
void							hash_free(t_hash_table *hash);
int								hash_check(t_hash_table *hash,
												int index, char *name);
t_room							*hash_search(t_hash_table *hash, int index, char *name);

#endif
