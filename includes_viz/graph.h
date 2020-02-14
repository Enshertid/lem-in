/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 22:10:16 by dbendu            #+#    #+#             */
/*   Updated: 2020/02/05 15:49:09 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPH_H
# define GRAPH_H

# include "libft.h"
# include "flags.h"
# include "room.h"
# include "hashtable.h"

typedef struct			s_link
{
	t_room				*room1;
	t_room				*room2;
}						t_link;

typedef struct			s_graph
{
	t_coord				center;
	int					ants;
	t_coord				*basic_coords;
	t_room				*rooms;
	t_link				*links;
	t_map				rooms_map;
}						t_graph;

t_graph					graph_create(void);
void					graph_destroy(t_graph *graph);

#endif
