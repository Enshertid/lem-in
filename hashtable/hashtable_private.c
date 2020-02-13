/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable_private.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 21:30:20 by dbendu            #+#    #+#             */
/*   Updated: 2020/02/04 22:40:46 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtable.h"
#include "hashtable_private.h"

t_uint64		hash_code(char *str)
{
	size_t			iter;
	size_t			len;
	t_uint64		hashcode;

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
