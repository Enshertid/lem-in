/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 02:25:07 by ymanilow          #+#    #+#             */
/*   Updated: 2020/02/14 03:04:17 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void			sort_ways_arr(t_way *ways_arr, int j)
{
	int				i;
	t_way			temp;

	j--;
	while (j > 0)
	{
		i = 0;
		while (i < j)
		{
			if (ways_arr[i].weight > ways_arr[j].weight)
			{
				temp = ways_arr[i];
				ways_arr[i] = ways_arr[j];
				ways_arr[j] = temp;
			}
			++i;
		}
		--j;
	}
}

// static t_ant		*create_ants(int ants_amount, t_way *ways_arr,
// 															int ways_amount)
// {
// 	t_ant			*ants;
// 	int				iter;
// 	int				ways;

// 	ants = malloc(sizeof(t_ant) * ants_amount);
// 	if (!ants)
// 		exit(1);
// 	iter = 0;
// 	ways = 1;
// 	while (iter < ants_amount)
// 	{
// 		while (ways_amount > 1 && ants_amount - iter == ways_arr[ways_amount].weight)
// 			ways_amount--;
// 		while (ways < ways_amount && iter == ways_arr[ways].weight)
// 			ways++;
// 		ants[iter].is_active = TRUE;
// 		ants[iter].cur_room = ways_arr[iter % ways_amount].head;
// 		++iter;
// 	}
// 	return (ants);
// }

// static void			print_ant(t_ant *ant, int cur_ant)
// {
// 	char *str;

// 	buf_add_chr('L', 1);
// 	str = ft_itoa(cur_ant + 1);
// 	buf_add_str(str);
// 	free(str);
// 	buf_add_chr('-', 1);
// 	buf_add_str(ant->cur_room->next->room->name);
// 	buf_add_chr(' ', 1);
// 	ant->cur_room = ant->cur_room->next;
// }

// static void			print_ants(t_ant *ants, int ants_amount, int ways_amount)
// {
// 	int					day;
// 	int					active_ants;
// 	int					cur_ant;
// 	int					ants_started_at_this_day;

// 	active_ants = ants_amount;
// 	day = 1;
// 	while (active_ants)
// 	{
// 		cur_ant = -1;
// 		ants_started_at_this_day = ft_min(ants_amount, day * ways_amount);
// 		while (++cur_ant < ants_started_at_this_day)
// 			if (ants[cur_ant].is_active)
// 			{
// 				print_ant(ants + cur_ant, cur_ant);
// 				if (!ants[cur_ant].cur_room->next)
// 				{
// 					ants[cur_ant].is_active = FALSE;
// 					--active_ants;
// 				}
// 			}
// 		buf_add_chr('\n', 1);
// 		++day;
// 	}
// }

void				print(t_ways *ways, int ants_amount)
{
	// t_ant				*ants;

	(void)ants_amount;
	sort_ways_arr(ways->way_ar, ways->iters.col);
	ft_print(ways);
	// ants = create_ants(ants_amount, ways->way_ar, ways->iters.col);
	// print_ants(ants, ants_amount, ways->iters.col);
	// free(ants);
}
