/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_find.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 21:35:04 by dbendu            #+#    #+#             */
/*   Updated: 2020/02/04 11:58:16 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

static void			*find_node(t_node *head, void *key)
{
	while (TRUE)
	{
		if (ft_strequ(head->key, key))
			break ;
		else if (ft_strcmp(head->key, key) < 0 && head->right)
			head = head->right;
		else if (head->left)
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
