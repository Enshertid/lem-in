/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   private_apply_flags.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 22:40:19 by user              #+#    #+#             */
/*   Updated: 2020/02/05 14:58:53 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private_data.h"

void				apply_flags(t_data *data)
{
	if (data->flags & FLAG_ADD_Z)
		add_z(data->graph.basic_coords);
	if (data->flags & FLAG_DEL_DEAD_LINES)
		del_dead_lines(data);
	if (data->flags & FLAG_MARK_WAYS)
		mark_ways(data);
}
