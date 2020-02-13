/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_destroy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 18:17:04 by user              #+#    #+#             */
/*   Updated: 2020/02/13 13:08:53 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animation.h"

void	animation_destroy(t_animation *animation)
{
	int iter;

	iter = 0;
	while (iter < animation->ants_amount)
	{
		vec_clear(&animation->ants[iter].way);
		++iter;
	}
	vec_clear(&animation->ants);
}
