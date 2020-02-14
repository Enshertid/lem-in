/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <dbendu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 21:35:28 by dbendu            #+#    #+#             */
/*   Updated: 2020/01/25 21:42:35 by dbendu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

t_tree					*tree_create(void)
{
	t_tree			*tree;

	tree = malloc(sizeof(t_tree));
	tree->head = NULL;
	return (tree);
}
