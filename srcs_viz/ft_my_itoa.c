/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_my_itoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 04:30:09 by ymanilow          #+#    #+#             */
/*   Updated: 2020/02/14 04:30:19 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_my_itoa(__int128_t num, char *str, unsigned base, unsigned is_upper)
{
	const char	*alphabet = is_upper ? "0123456789ABCDEF" : "0123456789abcdef";
	char		*iter;
	size_t		numsize;

	numsize = sizeof_num(num, base);
	if (!str)
		str = malloc(numsize + (num < 0) + 1);
	iter = str + numsize + (num < 0);
	*iter-- = '\0';
	if (base == 10 && num < 0)
	{
		*str = '-';
		num = -num;
	}
	if (!num)
		*iter = '0';
	while (num)
	{
		*iter-- = alphabet[num % base];
		num /= base;
	}
	return (str);
}
