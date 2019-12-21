/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_links.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 18:41:47 by ymanilow          #+#    #+#             */
/*   Updated: 2019/12/21 21:36:47 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void					ft_check_links_repeat(t_room room, char *name)
{
	int			i;

	i = -1;
	while (++i < room.iter)
	{
		if (ft_strequ(room.links[i]->name, name))
			ft_error("link repeats\n", 100);
	}
}

void					ft_malloc_links(t_room *room, t_room *link)
{
	t_room		**tmp;
	int			i;

	if (!room->link_presence)
	{
		room->col = 1;
		room->iter = 0;
		room->link_presence = TRUE;
		room->links = malloc(sizeof(t_room*) * room->col);
	}
	else if (room->iter >= room->col)
	{
		i = -1;
		tmp = malloc(sizeof(t_room*) * (room->col + 1));
		while (++i < room->col)
			tmp[i] = room->links[i];
		free(room->links);
		room->links = tmp;
		room->col++;
	}
	room->links[room->iter] = link;
	room->iter++;
}

void					ft_link_found(t_data *data, t_room *room, char *str)
{
	int			i;

	i = -1;
	while (++i <= data->num_of_rooms)
	{
		if (ft_strequ(data->rooms[i].name, str))
		{
			data->flag_not_error_link2 = TRUE;
			if (data->rooms[i].link_presence)
				ft_check_links_repeat(*room, str);
			ft_malloc_links(room, &data->rooms[i]);
			ft_malloc_links(&data->rooms[i], room);
			break;
		}
		else
			data->flag_not_error_link2 = FALSE;
	}
	if (!data->flag_not_error_link2)
		ft_error("second name in link is invalid", 6);
}

void					ft_check_links(t_data *data, char **line)
{
	char			**str;
	int				i;

	i = -1;
	data->flag_link = TRUE;
	str = ft_strsplit(*line, '-');
	while (++i <= data->num_of_rooms)
	{
		if (ft_strequ(data->rooms[i].name, str[0]))
		{
			data->flag_not_error_link1 = TRUE;
			if (data->rooms[i].link_presence)
				ft_check_links_repeat(data->rooms[i], str[0]);
			ft_link_found(data, &data->rooms[i], str[1]);
			break;
		}
		else
			data->flag_not_error_link1 = FALSE;
	}
	if (!data->flag_not_error_link1)
		ft_error("first name in link is invalid\n", 6);
	ft_strdel(line);
	ft_free(str, 2);
}