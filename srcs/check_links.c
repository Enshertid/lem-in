/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_links.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 18:41:47 by ymanilow          #+#    #+#             */
/*   Updated: 2019/12/24 13:21:20 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"


void					ft_malloc_links(t_room *room, t_room *link)
{
	t_room		*tmp;
	int			i;

	if (!room->link_presence)
	{
		room->iters.col = 5;
		room->iters.iter = 0;
		room->link_presence = TRUE;
		room->links = malloc(sizeof(t_room) * room->iters.col);
	}
	else if (room->iters.iter >= room->iters.col)
	{
		i = -1;
		tmp = malloc(sizeof(t_room) * (room->iters.col + 5));
		while (++i < room->iters.col)
			tmp[i].links = room[i].links;
		free(room->links);
		room->links = tmp;
		room->iters.col += 5;
	}
	room->links[room->iters.iter] = *link;
	room->iters.iter++;
}

void					ft_link_found(t_data *data, t_room *room, char *str)
{
	int			i;

	i = -1;
	while (++i <= data->iters.iter)
	{
		if (ft_strequ(data->rooms[i].name, str))
		{
			data->flags.flag_not_error_link2 = TRUE;
			ft_malloc_links(room, &data->rooms[i]);
			ft_malloc_links(&data->rooms[i], room);
			break;
		}
		else
			data->flags.flag_not_error_link2 = FALSE;
	}
	if (!data->flags.flag_not_error_link2)
		ft_error("second name in link is invalid", 6);
}

void					ft_check_links(t_data *data, char **line)
{
	char			**str;
	int				i;

	i = -1;
	data->flags.flag_link = TRUE;
	str = ft_strsplit(*line, '-');
	while (++i <= data->iters.iter)
	{
		if (ft_strequ(data->rooms[i].name, str[0]))
		{
			data->flags.flag_not_error_link1 = TRUE;
			ft_link_found(data, &data->rooms[i], str[1]);
			break;
		}
		else
			data->flags.flag_not_error_link1 = FALSE;
	}
	if (!data->flags.flag_not_error_link1)
		ft_error("first name in link is invalid\n", 6);
	ft_strdel(line);
	ft_free(str, 2);
}