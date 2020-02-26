/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 02:25:07 by ymanilow          #+#    #+#             */
/*   Updated: 2020/02/26 16:46:29 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void			print_ant(t_ant *ant, int cur_ant)
{
	char *str;

	buf_add_chr('L', 1);
	str = ft_itoa(cur_ant + 1);
	buf_add_str(str);
	free(str);
	buf_add_chr('-', 1);
	buf_add_str(ant->cur_room->next->room->name);
	buf_add_chr(' ', 1);
}

static void			cycle(t_ant *ants_arr, int started_ants)
{
	t_bool			is_newline;
	int				cur_ant;

	cur_ant = 0;
	is_newline = FALSE;
	while (cur_ant < started_ants)
	{
		if (ants_arr[cur_ant].is_active)
		{
			is_newline = TRUE;
			print_ant(ants_arr + cur_ant, cur_ant);
			ants_arr[cur_ant].cur_room = ants_arr[cur_ant].cur_room->next;
			if (!ants_arr[cur_ant].cur_room->next)
				ants_arr[cur_ant].is_active = FALSE;
		}
		++cur_ant;
	}
	if (is_newline)
		buf_add_chr('\n', 1);
}

static void			print_ants(t_ant *ants_arr, int ants_amount,
											t_ways *ways, int ways_amount)
{
	int				day;
	int				cur_way;
	int				started_ants;

	day = 0;
	started_ants = 0;
	while (day < ways->days)
	{
		while (ways_amount > 0 &&
				ways->way_ar[ways_amount - 1].weight > ways->days - day)
			--ways_amount;
		cur_way = 0;
		while (cur_way < ways_amount && started_ants + cur_way < ants_amount)
		{
			ants_arr[started_ants + cur_way].cur_room =
									ways->way_ar[cur_way].head;
			++cur_way;
		}
		started_ants += cur_way;
		cycle(ants_arr, started_ants);
		++day;
	}
}

void				print_start_end(t_ant *ants_arr, int ants_amount,
															t_ways *ways)
{
	int ant;

	ant = -1;
	while (++ant < ants_amount)
	{
		ants_arr[ant].cur_room = ways->way_ar[0].head;
		print_ant(ants_arr + ant, ant);
	}
	buf_add_chr('\n', 1);
}

void				print(t_ways *ways, int ants_amount)
{
	t_ant				*ants;

	sort_ways_arr(ways->way_ar, ways->iters.col);
	ants = create_ants(ants_amount);
	if (ways->days == 1)
		print_start_end(ants, ants_amount, ways);
	else
		print_ants(ants, ants_amount, ways, ways->iters.col);
	free(ants);
}
