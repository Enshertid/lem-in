/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 19:07:02 by ymanilow          #+#    #+#             */
/*   Updated: 2020/02/14 03:08:19 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include "graph.h"
# include "hash_table.h"
# include "turn.h"
# include "ways.h"
# include "ft_buf.h"

typedef struct				s_ant
{
	t_bool					is_active;
	t_way_room				*cur_room;
}							t_ant;

typedef struct				s_flags_pars
{
	t_bool					flag_ants;
	t_bool					flag_links;
	t_bool					flag_start;
	t_bool					flag_end;
	t_bool					flag_room;
}							t_flags_pars;

typedef struct				s_pars
{
	int						fd;
	int						hash_f;
	int						hash_s;
	t_room					*room_f;
	t_room					*room_s;
	char					*line;
	char					**str;
}							t_pars;

typedef struct				s_data
{
	t_graph					graph;
	t_flags_pars			flags;
	t_hash_table			hash;
	t_turn					turn;
	t_pars					pars;
	t_storage_w				ways;
	t_way					way_for_algo;
	int						ants;
}							t_data;

void						parsing(t_data *data, char **av);
int							get_next_line(const int fd, char **line);

void						get_way(t_graph *graph, t_way *way);
void						bfs_algo(t_graph *graph, t_turn *turn, t_way *way);
void						dijkstra_algo(t_graph *graph, t_turn *turn,
																t_way *way);
void						dijkstra_algo_modifide(t_graph *graph,
													t_turn *turn, t_way *way);

void						set_ways_to_the_next_iteration(t_ways *prev_iter,
															t_ways *next_iter);
t_bool						search_graph_for_way_with_common_links(t_graph
											*graph, t_turn *turn, t_way *way);
void						wrap_directions(t_way *way, int num_of_way);
void						algo(t_data *data);
void						print(t_ways *ways, int ants_amount);
#endif
