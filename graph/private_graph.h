/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   private_graph.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 19:09:20 by user              #+#    #+#             */
/*   Updated: 2020/02/05 16:20:25 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"
#include "mlx_defines.h"

void			get_rooms_and_coords(t_graph *graph, char **str);
t_map			create_rooms_map(t_room *rooms);
t_link			*get_links(t_map *rooms_map, char *str);
