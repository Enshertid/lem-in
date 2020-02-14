/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable_private.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 21:30:20 by dbendu            #+#    #+#             */
/*   Updated: 2020/02/14 04:28:05 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtable.h"
#include "hashtable_private.h"

uint64_t		hash_code(char *str)
{
	size_t			iter;
	size_t			len;
	uint64_t		hashcode;

	hashcode = 0;
	iter = 0;
	len = ft_strlen(str);
	while (iter < len)
	{
		hashcode += str[iter] * ft_ipow(31, len - iter - 1);
		++iter;
	}
	return (hashcode);
}
