/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_destroy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 18:17:04 by user              #+#    #+#             */
/*   Updated: 2020/02/25 21:44:17 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animation.h"
#include "vector.h"

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
