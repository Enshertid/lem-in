/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 02:25:07 by ymanilow          #+#    #+#             */
/*   Updated: 2020/02/26 12:49:50 by ymanilow         ###   ########.fr       */
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

static t_ant		*create_ants(int ants_amount)
{
	t_ant			*ants;
	int				iter;

	ants = malloc(sizeof(t_ant) * ants_amount);
	if (!ants)
		exit(1);
	iter = 0;
	while (iter < ants_amount)
	{
		ants[iter].is_active = TRUE;
		++iter;
	}
	return (ants);
}

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

static void			print_ants(t_ant *ants_arr, int ants_amount, t_ways *ways, int ways_amount)
{
	int				day;
	int				cur_ant;
	int				cur_way;
	int				started_ants;
	int				is_newline;

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
			ants_arr[started_ants + cur_way].cur_room = ways->way_ar[cur_way].head;
			++cur_way;
		}
		started_ants += cur_way;
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
		++day;
	}
}

void				print(t_ways *ways, int ants_amount)
{
	t_ant				*ants;

	sort_ways_arr(ways->way_ar, ways->iters.col);
	ants = create_ants(ants_amount);
	print_ants(ants, ants_amount, ways, ways->iters.col);
	// ft_print(ways);
	free(ants);
}
