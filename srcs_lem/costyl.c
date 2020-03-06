/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costyl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 14:38:08 by ymanilow          #+#    #+#             */
/*   Updated: 2020/03/06 14:38:41 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void						ft_costyl(t_data *data)
{
	buf_add_str(data->pars.line);
	buf_add_chr('\n', 1);
	pars_link(data);
	ft_strdel(&data->pars.line);
	ft_free(data->pars.str, 2);
}
