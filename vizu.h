/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vizu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <dbendu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 18:16:32 by dbendu            #+#    #+#             */
/*   Updated: 2019/12/19 20:38:53 by dbendu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIZU_H
# define VIZU_H


#include <stdio.h>
#include "mlx.h"
#include "libft.h"

# define WIDTH		2500
# define HEIGHT		1350

# define ESC		53

typedef struct		s_wnd
{
	void			*mlxptr;
	void			*wndptr;
	void			*imgptr;

	char			*img;
	int				bytes;
	int				size_line;
	int				endian;
}					t_wnd;

typedef struct		s_room
{
	t_int32			x;
	t_int32			y;
	const char		*name;
	int				ants;
}					t_room;

typedef struct		s_data
{
	t_room			*rooms;
	t_int32			ants;
}					t_data;

int					vizu_exit(t_wnd *wnd);
int					key_press(int keycode, t_wnd *wnd);
t_data				get_map(const char *file);

#endif