/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 19:09:22 by ymanilow          #+#    #+#             */
/*   Updated: 2019/12/20 13:52:43 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int						main(int ac, char **av)
{
	t_data			data;

	ft_memset(&data, 0 , sizeof(t_data));
	ft_parsing(ac, av, &data);
	ft_printf("ants = %d\n" , data.ants);
	int i;
	i = 0;
//	ft_printf("name of first room is ---> %s\n" , data.rooms[0].name);
//	while (++i <= data.num_of_rooms)
//	{
//		ft_printf("name of room is ==> %s\nnumber of room is ==>%d\n", data.rooms[i].name, data.rooms[i].num_of_room);
//	}
//	ft_printf("name of end room is ==> %s", data.end.name);
	ft_printf("name of room --> %s number of room i --> %d\n", data.rooms[i].name, data.rooms[i].num_of_room);
	i = -1;
	while (++i < data.rooms[i].col)
		ft_printf("name of link of this room --> %s, number of room (link) --> %d\n", data.rooms->links[i].name,
				data.rooms->links[i].num_of_room);
	return (0);
}