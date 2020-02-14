/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 21:40:33 by dbendu            #+#    #+#             */
/*   Updated: 2020/02/14 04:27:50 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAGS_H
# define FLAGS_H

# include "libft.h"

# define FLAG_ADD_Z				(((uint64_t)1) << 1)
# define FLAG_DEL_DEAD_LINES	(((uint64_t)1) << 2)
# define FLAG_MARK_WAYS			(((uint64_t)1) << 3)

#endif
