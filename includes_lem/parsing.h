/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 21:32:08 by ymanilow          #+#    #+#             */
/*   Updated: 2020/03/06 14:39:40 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "lem_in.h"
# include "graph.h"

void					check_comment(t_data *data);
void					check_side_room(t_data *data);
void					check_rooms(t_data *data);
void					check_links(t_data *data);
void					pre_fill_fork(t_room **room);

void					relink_hash_table(t_hash_table *hash,
											t_graph *graph, int size);
void					remalloc_of_graph(t_data *data);
void					final_remalloc_graph(t_data *data);
void					ft_costyl(t_data *data);
void					pars_link(t_data *data);

#endif
