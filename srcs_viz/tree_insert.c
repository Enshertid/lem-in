/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <dbendu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 21:34:57 by dbendu            #+#    #+#             */
/*   Updated: 2020/02/14 01:35:48 by dbendu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

static t_node		*node_create(void *key, void *value)
{
	t_node			*node;

	node = ft_malloc(sizeof(t_node));
	node->key = key;
	node->value = value;
	node->left = NULL;
	node->right = NULL;
	node->next = NULL;
	return (node);
}

static void			insert(t_node *head, t_node *node)
{
	int cmp;

	while (TRUE)
	{
		cmp = ft_strcmp(head->key, node->key);
		if (!cmp)
			break ;
		else if (cmp > 0 && head->left)
			head = head->left;
		else if (cmp < 0 && head->right)
			head = head->right;
		else
			break ;
	}
	if (ft_strequ(node->key, head->key))
	{
		node->next = head->next;
		head->next = node->next;
	}
	else if (ft_strcmp(node->key, head->key) < 0)
		head->left = node;
	else
		head->right = node;
}

void				tree_insert(t_tree *tree, void *key, void *value)
{
	t_node			*node;

	node = node_create(key, value);
	if (!tree->head)
		tree->head = node;
	else
		insert(tree->head, node);
}
