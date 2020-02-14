/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   private_get_flags.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 01:39:28 by dbendu            #+#    #+#             */
/*   Updated: 2020/02/14 04:27:21 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private_data.h"

uint64_t			get_flags(char **argv)
{
	uint64_t		flags;

	flags = 0;
	while (*++argv)
	{
		if (**argv != '-')
			continue;
		while (*(++*argv))
		{
			if (**argv == 'a')
				flags |= FLAG_ADD_Z;
			else if (**argv == 'd')
				flags |= FLAG_DEL_DEAD_LINES;
			else if (**argv == 'm')
				flags |= FLAG_MARK_WAYS;
		}
	}
	return (flags);
}
