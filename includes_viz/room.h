/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 21:47:15 by dbendu            #+#    #+#             */
/*   Updated: 2020/02/05 16:26:59 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROOM_H
# define ROOM_H

# include "libft.h"
# include "coord.h"

typedef struct			s_room
{
	char				*name;
	struct s_room		**links;
	t_coord				coord;
	int					color;
}						t_room;

#endif
