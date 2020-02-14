/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 21:40:33 by dbendu            #+#    #+#             */
/*   Updated: 2020/02/03 15:27:54 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAGS_H
# define FLAGS_H

# include "libft.h"

# define FLAG_ADD_Z				(((t_uint64)1) << 1)
# define FLAG_DEL_DEAD_LINES	(((t_uint64)1) << 2)
# define FLAG_MARK_WAYS			(((t_uint64)1) << 3)

#endif
