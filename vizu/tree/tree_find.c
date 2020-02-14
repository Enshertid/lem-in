/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_find.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <dbendu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 21:35:04 by dbendu            #+#    #+#             */
/*   Updated: 2020/02/14 00:27:48 by dbendu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

static void			*find_node(t_node *head, void *key)
{
	int cmp;

	while (TRUE)
	{
		cmp = ft_strcmp(head->key, key);
		if (!cmp)
			break ;
		else if (cmp < 0 && head->right)
			head = head->right;
		else if (cmp > 0 && head->left)
			head = head->left;
		else
			return (NULL);
	}
	return (head->value);
}

void				*tree_find(t_tree *tree, void *key)
{
	if (!tree || !tree->head || !key)
		return (NULL);
	else
		return (find_node(tree->head, key));
}
