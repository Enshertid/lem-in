/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 19:07:02 by ymanilow          #+#    #+#             */
/*   Updated: 2020/01/17 21:48:04 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN
#define LEM_IN

#include "libft.h"
#include "graph.h"

typedef struct				s_flags
{
	t_bool					flag_ants;
	t_bool					flag_links;
	t_bool					flag_start;
	t_bool					flag_end;
	t_bool					flag_rooms;
}							t_flags;

//typedef struct s_graph;
//typedef struct s_graph t_graph;

typedef struct				s_data
{
	t_graph					graph;
	t_flags					flags;
	int						fd;
	int						ants;
	char					**line;
}							t_data;

void						parsing(t_data *data, char **av);

#endif
