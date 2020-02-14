/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <dbendu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 21:34:32 by dbendu            #+#    #+#             */
/*   Updated: 2020/01/25 22:25:37 by dbendu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_H
# define TREE_H

# include "libft.h"

typedef struct			s_node
{
	void				*key;
	void				*value;
	struct s_node		*left;
	struct s_node		*right;
	struct s_node		*next;
}						t_node;

typedef struct			s_tree
{
	t_node				*head;
}						t_tree;

t_tree					*tree_create(void);
void					tree_destroy(t_tree *tree);
void					tree_insert(t_tree *tree, void *key, void *value);
void					*tree_find(t_tree *tree, void *key);
void					tree_print(t_tree *tree);

#endif
