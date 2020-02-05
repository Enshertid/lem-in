//
// Created by Naumenko on 03.02.2020.
//

#include "lem_in.h"

void				controller_of_condition(t_room *room)
{
	int i;

	i = -1;
	ft_printf("name of room is %s\n", room->name);
	while (++i < room->iter.i)
	{
		if (room->links[i].condition)
			ft_printf("condition of link with room %s is TRUE\n",room->links[i].link->name);
		else
			ft_printf("condition of link with room %s is FALSE\n", room->links[i].link->name);
	}
}

void				put_out_links_of_rooms(t_data *data)
{
	int i = -1;
	int j;
	while (++i < data->graph.iter.col)
	{
		j = -1;
		ft_printf("room %s has next links:\n",data->graph.rooms[i]->name);
		while (++j < data->graph.rooms[i]->iter.i)
			ft_printf("%s\n",data->graph.rooms[i]->links[j].link->name);
	}
}

void				put_out_way(t_way way)
{
	t_way_room *tmp;

	tmp = way.head;
	while (tmp)
	{
		ft_printf("%s\n",tmp->room->name);
		tmp = tmp->next;
	}
}

void				put_out_array_of_ways(t_ways *ways)
{
	int i;

	i = -1;
	while (++i < ways->iters.col)
	{
		ft_printf("num_of_way_is ==> %d\n", i + 1);
		put_out_way(ways->way_ar[i]);
	}
}