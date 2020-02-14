/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_create.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 21:53:15 by dbendu            #+#    #+#             */
/*   Updated: 2020/02/05 15:50:06 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animation.h"
#include "private_animation.h"

t_animation			animation_create(int ants, t_map *rooms_map, t_room *rooms)
{
	t_animation		animation;

	animation.is_animation_active = FALSE;
	animation.cur_day = 1;
	animation.ants_amount = ants;
	animation.ants_at_start = ants;
	animation.ants_at_finish = 0;
	animation.ants = get_ants_ways(ants, rooms_map, rooms);
	animation.cur_tick = 0;
	animation.ticks = 100;
	animation.visited_rooms = NULL;
	return (animation);
}
