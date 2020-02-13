/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 21:35:16 by dbendu            #+#    #+#             */
/*   Updated: 2020/02/13 13:24:11 by user             ###   ########.fr       */
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

// static void				destroy(t_node *head)
// {
// 	t_node		**cur_nodes;
// 	t_node		**next_nodes;
// 	size_t		cur_size;
// 	size_t		iter;

// 	cur_nodes = vec_init(0, 1, sizeof(t_node*));
// 	vec_pushback(&cur_nodes, &head);
// 	while ((cur_size = vec_size(cur_nodes)))
// 	{
// 		next_nodes = vec_init(0, 1, sizeof(t_node*));
// 		iter = 0;
// 		while (iter < cur_size)
// 		{
// 			if (cur_nodes[iter]->left)
// 				vec_pushback(&next_nodes, &cur_nodes[iter]->left);
// 			if (cur_nodes[iter]->right)
// 				vec_pushback(&next_nodes, &cur_nodes[iter]->right);
// 			node_destroy(cur_nodes[iter]);
// 			++iter;
// 		}
// 		vec_clear(&cur_nodes);
// 		cur_nodes = next_nodes;
// 	}
// 	vec_clear(&cur_nodes);
// }

void					tree_destroy(t_tree *tree)
{
	if (tree && tree->head)
		node_destroy(tree->head);
	if (tree)
		free(tree);
}
