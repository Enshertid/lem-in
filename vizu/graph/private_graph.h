/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   private_graph.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <dbendu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 19:09:20 by user              #+#    #+#             */
/*   Updated: 2020/02/14 02:13:56 by dbendu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRIVATE_GRAPH_H
# define PRIVATE_GRAPH_H

# include "graph.h"
# include "mlx_defines.h"

void			get_rooms_and_coords(t_graph *graph, char **str);
t_map			create_rooms_map(t_room *rooms);
t_link			*get_links(t_map *rooms_map, char *str);

#endif
