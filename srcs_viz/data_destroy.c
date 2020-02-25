/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 01:38:28 by dbendu            #+#    #+#             */
/*   Updated: 2020/02/25 21:44:43 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

void			data_destroy(t_data *data)
{
	wnd_destroy(&data->wnd);
	graph_destroy(&data->graph);
	animation_destroy(&data->animation);
	(void)(data);
}
