/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 19:09:22 by ymanilow          #+#    #+#             */
/*   Updated: 2019/12/19 18:47:57 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int						main(int ac, char **av)
{
	t_data			data;

	ft_memset(&data, 0 , sizeof(t_data));
	ft_parsing(ac, av, &data);
	ft_printf("ants = %d\n" , data.ants);
	ft_printf("name of first room is ---> %s" , data.rooms[0].name);
	return (0);
}