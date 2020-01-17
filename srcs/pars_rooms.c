/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_rooms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 21:31:52 by ymanilow          #+#    #+#             */
/*   Updated: 2020/01/17 22:27:30 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void					check_start(t_data *data)
{
	ft_printf("%s", data->line);
}

void					check_end(t_data *data)
{
	ft_printf("%s", data->line);
}

void					check_side_room(t_data *data)
{
	if (ft_strequ(*(data->line), "#start"))
		check_start(data);
	else if (ft_strequ(*(data->line), "#end"))
		check_end(data);
}

void					check_rooms(t_data *data)
{
	ft_printf("%s", data->line);
}