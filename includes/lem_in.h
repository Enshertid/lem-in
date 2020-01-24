/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 19:07:02 by ymanilow          #+#    #+#             */
/*   Updated: 2020/01/24 21:24:21 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN
#define LEM_IN

 #include "libft.h"
#include "graph.h"
#include "hash_table.h"
#include "turn.h"
#include "ways.h"

typedef struct				s_flags
{
	t_bool					flag_ants;
	t_bool					flag_links;
	t_bool					flag_start;
	t_bool					flag_end;
	t_bool					flag_room;
}							t_flags;

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
	t_flags					flags;
	t_hash_table			hash;
	t_turn					turn;
	t_pars					pars;
	t_storage_w 			ways;
	t_way					way_for_algo;
	int						ants;
}							t_data;

void						parsing(t_data *data, char **av);
int							get_next_line(const int fd, char **line);

void						bfs_algo(t_graph *graph, t_turn *turn, t_way *way);
void						dijkstra_algo(t_graph *graph, t_turn *turn, t_way *way);
void						wrap_directions(t_way *way);
void						set_ways_to_the_next_iteration(t_ways *prev_iter, t_ways *next_iter);
void						dijkstra_algo_modifide(t_graph *graph, t_turn *turn, t_way *way);

#endif
