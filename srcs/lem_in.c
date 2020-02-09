/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 19:43:23 by ymanilow          #+#    #+#             */
/*   Updated: 2020/02/09 19:01:24 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void				free_data(t_data *data)
{
	hash_free(&data->hash);
	way_storage_free(&data->ways);
	graph_free(&data->graph);
	turn_free(&data->turn);
}

int					optimal(t_ways *ways, int ants)
{
	int i;

	i = -1;
	while (++i < ways->iters.col)
		ways->weight += way_weight(&ways->way_ar[i]);
	if (ants <= ways->weight)
		return (1);
	return (0);
}

void 				add_algo_way_to_array(t_ways *ways, t_way *new)
{
	ways->way_ar[ways->iters.col - 1].head = new->head;
	ways->way_ar[ways->iters.col - 1].tail = new->tail;
	new->head = NULL;
	new->tail = NULL;
}

void				get_way1(t_graph *graph, t_way *way)
{
		t_room					*tmp;
		ssize_t					i;

		tmp = graph->rooms[graph->iter.col - 1];
		while (tmp)
		{
			if (tmp->flags.flag_of_second && tmp->flags.flag2)
			{
				way_point_add(way, way_point_create(tmp));
				tmp->flags.flag_of_second = FALSE;
				tmp = tmp->prev_in_algo[1].link;
			}
			else
			{
				way_point_add(way, way_point_create(tmp));
				tmp = tmp->prev_in_algo[0].link;
			}
		}
//		way_point_add(way, way_point_create(tmp));
		i = -1;
		while (++i < graph->iter.col)
		{
			graph->rooms[i]->flags.flag = FALSE;
			graph->rooms[i]->flags.flag_of_way = FALSE;
			graph->rooms[i]->prev_in_algo[0].link = NULL;
			graph->rooms[i]->prev_in_algo[1].link = NULL;
			graph->rooms[i]->distance_first = MAX_INT;
			graph->rooms[i]->distance_second = MAX_INT;
			graph->rooms[i]->flags.flag_of_second = FALSE;
		}
		graph->rooms[0]->distance_first = 0;
		graph->rooms[0]->distance_second = 0;
}

void				usual_rooms(t_turn *turn, int i)
{
	if (turn->arr[0]->distance_first + 1 < turn->arr[0]->links[i].link->distance_first)
	{
		turn->arr[0]->links[i].link->distance_first = turn->arr[0]->distance_first + 1;
		turn->arr[0]->links[i].link->prev_in_algo[0].link = turn->arr[0];
		turn_add(turn, turn->arr[0]->links[i].link, FALSE);
	}
}

	//void 				rooms_of_ways(void)
	//{
	/* if (номера путей одинаковы)
	 * 		if (текущая комната только с флагом первого вхождения)
	 * 		{
	 * 			if (следующая комната без флагов)
	 * 			{
	 *				сравнить дистанции первой позиции
	 *				при попадании занести в очередь
	 * 			}
	 * 			else if (следующая комната с флагом  первого вхождения)
	 * 			{
	 * 				сравнить дистанции первой позиции первой комнаты и второй позиции второй комнаты
	 * 				при попадании занести в очередь
	 * 				пометить как второе вхождение
	 * 			}
	 *		 else
	 * 			continue;
	 *else if (номера путей различны)
	 * 		if (текущая комната только с первым вхождением)
	 * 		{
	 * 			сравнить дистанции первой позиции
	 * 			при попадании занести в очередь
	 * 		}
	 * 		else
	 * 		{
	 *
	 * 		}
	 */
//}

void				rooms_of_way(t_turn *turn, int i)
{
	if (turn->arr[0]->num_of_way == turn->arr[0]->links[i].link->num_of_way)
	{
		if (!turn->arr[0]->flags.flag_of_second)
		{
			if (turn->arr[0]->distance_first - 1 < turn->arr[0]->links[i].link->distance_second)
			{
				if (!turn->arr[0]->flags.flag1)
					turn->arr[0]->flags.flag2 = TRUE;
				turn->arr[0]->links[i].link->distance_second = turn->arr[0]->distance_first - 1;
				turn->arr[0]->links[i].link->prev_in_algo[1].link = turn->arr[0];
				turn->arr[0]->links[i].link->flags.flag_of_second = TRUE;
				turn_add(turn, turn->arr[0]->links[i].link, FALSE);
			}
		}
		else
		{
			if (turn->arr[0]->distance_second - 1 < turn->arr[0]->links[i].link->distance_second)
			{
				if (!turn->arr[0]->flags.flag1)
					turn->arr[0]->flags.flag2 = TRUE;
				turn->arr[0]->links[i].link->distance_second = turn->arr[0]->distance_second - 1;
				turn->arr[0]->links[i].link->prev_in_algo[1].link = turn->arr[0];
				turn->arr[0]->links[i].link->flags.flag_of_second = TRUE;
				turn_add(turn, turn->arr[0]->links[i].link, FALSE);
			}
		}
	}
	else
	{
		if (!turn->arr[0]->flags.flag_of_second)
		{
			if (turn->arr[0]->distance_first + 1 < turn->arr[0]->links[i].link->distance_first)
			{
				if (!turn->arr[0]->flags.flag2)
					turn->arr[0]->flags.flag1 = TRUE;
				turn->arr[0]->links[i].link->distance_first = turn->arr[0]->distance_first + 1;
				turn->arr[0]->links[i].link->prev_in_algo[0].link = turn->arr[0];
				turn_add(turn, turn->arr[0]->links[i].link, FALSE);
			}
		}
		else if (turn->arr[0]->flags.flag_of_second)
		{
			if (turn->arr[0]->distance_second + 1 < turn->arr[0]->links[i].link->distance_first)
			{
				if (!turn->arr[0]->flags.flag2)
					turn->arr[0]->flags.flag1 = TRUE;
				turn->arr[0]->links[i].link->distance_first = turn->arr[0]->distance_second + 1;
				turn->arr[0]->links[i].link->prev_in_algo[0].link = turn->arr[0];
				turn_add(turn, turn->arr[0]->links[i].link, FALSE);
			}
		}
	}
}

void				get_out_of_way(t_turn *turn, int i)
{
//	if (!turn->arr[0]->flags.flag_of_second && !turn->arr[0]->flags.flag)
//	{
//		if (turn->arr[0]->distance_first + 1 < turn->arr[0]->links[i].link->distance_first)
//		{
//			turn->arr[0]->links[i].link->distance_first = turn->arr[0]->distance_first + 1;
//			turn->arr[0]->links[i].link->prev_in_algo[0].link = turn->arr[0];
//			turn->arr[0]->links[i].link->flags.flag_of_first = TRUE;
//			turn_add(turn, turn->arr[0]->links[i].link, FALSE);
//		}
//	}
	if (turn->arr[0]->flags.flag_of_second)
	{
		if (turn->arr[0]->distance_second + 1 < turn->arr[0]->links[i].link->distance_first)
		{
			turn->arr[0]->links[i].link->distance_first = turn->arr[0]->distance_second + 1;
			turn->arr[0]->links[i].link->prev_in_algo[0].link = turn->arr[0];
			turn_add(turn, turn->arr[0]->links[i].link, FALSE);
		}
	}
}


void				search_graph_for_way_with_common_links(t_graph *graph, t_turn *turn, t_way *way)
{
	int					i;

	turn_add(turn, graph->rooms[0], FALSE);
	while (turn->arr[0])
	{
 		i = -1;
		while (++i < turn->arr[0]->iter.i)
		{
			if (turn->arr[0]->links[i].status &&
			turn->arr[0]->links[i].link != graph->rooms[0] &&
			turn->arr[0] != graph->rooms[graph->iter.col - 1])
			{
				if (turn->arr[0]->flags.flag_of_way)
				{
					if (turn->arr[0]->links[i].link->flags.flag_of_way)
						rooms_of_way(turn, i);
					else if (!turn->arr[0]->links[i].link->flags.flag_of_way)
						get_out_of_way(turn, i);
				}
				else if (!turn->arr[0]->flags.flag)
					usual_rooms(turn, i);
			}
		}
		turn_del(turn);
	}
	get_way1(graph, way);
}

void				algo(t_data *data)
{
	int					i;
	int					j;

	j = 1;
	dijkstra_algo(&data->graph, &data->turn, &data->ways.ways[0].way_ar[0]);
	ft_printf("shortest way\n");
	put_out_way(data->ways.ways[0].way_ar[0]);
	set_ways_to_the_next_iteration(&data->ways.ways[0], &data->ways.ways[1]);
	while (!optimal(&data->ways.ways[j], data->ants))
	{
		ft_printf("\nnum of iter == %d\n\n",j);
		put_out_array_of_ways(&data->ways.ways[j]);
		i = -1;
		while (++i < data->ways.ways[j].iters.i)
			wrap_directions(&data->ways.ways[j].way_ar[i], i + 1);
		search_graph_for_way_with_common_links(&data->graph, &data->turn, &data->way_for_algo);
		ft_printf("\nway_out\n");
		put_out_way(data->way_for_algo);
		i = -1;
		combine_ways_and_cut_common_link(&data->way_for_algo, &data->ways.ways[j]);
		add_algo_way_to_array(&data->ways.ways[j], &data->way_for_algo);
		if (j < data->ways.iters.col - 1)
			set_ways_to_the_next_iteration(&data->ways.ways[j], &data->ways.ways[j + 1]);
		else
			break;
		j++;
	}
	ft_printf("\nnum of iter == %d\n",j);
	put_out_array_of_ways(&data->ways.ways[j]);
	//while (!optimal)
	/*{
	 * выключить связи в путях, направленные в конец
	 * нахожу кратчайший путь (путь с наибольшим потенциальным количеством общих ребер)(вспомогательный)
	 * перекидываю участки смежные с общими ребрами , удаляю ребра
	 * очищаю вспомогательный граф
	 * переношу связи в хранилище новой итерации
	 * }
	 */
}

int					main(int ac, char **av)
{
	t_data data;

	if (ac < 0)
		ft_error("haha, ac < 0\n", 1);
	ft_memset(&data, 0, sizeof(t_data));
	data.hash.hash_table = hash_array_create(HASH_SIZE);
	data.hash.size = HASH_SIZE;
	data.graph = set_graph();
	parsing(&data, av);
	way_storage_set(&data.graph, &data.ways);
//	put_out_links_of_rooms(&data);
	ft_printf("\n\n");
	data.turn.size= data.graph.iter.col;
	data.turn.arr = turn_create(data.turn.size);
	algo(&data);
	free_data(&data);
	return(0);
}
