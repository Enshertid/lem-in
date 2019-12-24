/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 22:45:36 by ymanilow          #+#    #+#             */
/*   Updated: 2019/12/24 15:14:33 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void						pop_front(t_data *data)
{
	int					i;

	data->tmp = data->rooms[0];
	i = 0;
	while (++i <= data->iters.iter)
		data->rooms[i - 1] = data->rooms[i];
	data->rooms[data->iters.col] = data->tmp;
}

void						pop_end(t_data *data)
{
	int					i;
	int					j;

	data->tmp = data->rooms[data->iters.col];
	i = data->iters.col;
	j = data->iters.col;
	while(--i >= 0)
		data->rooms[j--] = data->rooms[i];
	data->rooms[0] = data->tmp;
}

void						final_malloc(t_data *data)
{
	t_room					*tmp;
	int						i;

	if (data->iters.iter < data->iters.col)
	{
		i = -1;
		tmp = malloc(sizeof(t_room) * (data->iters.iter + 1));
		data->iters.col = data->iters.iter;
		while(++i < data->iters.col)
		{
			tmp[i].name = data->rooms[i].name;
			tmp[i].links = data->rooms[i].links;
		}
		tmp = ft_memcpy(tmp, data->rooms, sizeof(t_room) * data->iters.col);
		free(data->rooms);
		data->rooms = tmp;
	}
}

void						turn_with_remalloc_end(t_data *data, t_room *new)
{
	t_room				*tmp;
	int					i;

	if (!data->rooms || !new)
		ft_error("incorrect data in turn\n", 43);
	i = -1;
	tmp = malloc(sizeof(t_room) * (data->iters.col + 1));
	while(++i < data->iters.col)
	{
		tmp[i].name = data->rooms[i].name;
		tmp[i].links = data->rooms[i].links;
	}
	tmp = ft_memcpy(tmp, data->rooms, sizeof(t_room) * data->iters.col);
	free(data->rooms);
	data->rooms = tmp;
	data->iters.col++;
	if (new)
		data->rooms[data->iters.col] = *new;
}

void						turn_with_remalloc_start(t_data *data, t_room *new)
{
	t_room				*tmp;
	int					i;
	int					j;

	if (!data->rooms || !new)
		ft_error("incorrect data in turn\n", 43);
	i = data->iters.col + 1;
	j = data->iters.col + 1;
	data->iters.col++;
	tmp = malloc(sizeof(t_room) * (data->iters.col));
	while(--i >= 0)
	{
		tmp[--j].name = data->rooms[i].name;
		tmp[j].links = data->rooms[i].links;
	}
	tmp = ft_memcpy(tmp, data->rooms, data->iters.col);
	free(data->rooms);
	data->rooms = tmp;
	if (new)
		data->rooms[0] = *new;
}
