/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <dbendu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 21:35:16 by dbendu            #+#    #+#             */
/*   Updated: 2020/02/14 02:17:59 by dbendu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

static void				node_destroy(t_node *node)
{
	t_node		*temp;

	while (node)
	{
		temp = node->next;
		free(node->value);
		free(node);
		node = temp;
	}
}

void					tree_destroy(t_tree *tree)
{
	if (tree && tree->head)
		node_destroy(tree->head);
	if (tree)
		free(tree);
}
