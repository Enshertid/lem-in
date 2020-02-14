/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   private_get_flags.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <dbendu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 01:39:28 by dbendu            #+#    #+#             */
/*   Updated: 2020/02/14 01:39:29 by dbendu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private_data.h"

t_uint64			get_flags(char **argv)
{
	t_uint64		flags;

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
