/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wnd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 21:48:03 by dbendu            #+#    #+#             */
/*   Updated: 2020/02/05 15:27:31 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WND_H
# define WND_H

# include "mlx_defines.h"
# include "mlx.h"

typedef struct				s_img
{
	void					*imgptr;
	char					*img;
	int						bytes;
	int						size_line;
	int						endian;
	int						width;
	int						height;
}							t_img;

typedef struct				s_wnd
{
	void					*mlxptr;
	void					*wndptr;
	t_img					graph_img;
	t_img					ant_img;
	t_img					start_circle_img;
	t_img					end_circle_img;
	t_img					pentagon_img;
}							t_wnd;

t_wnd						wnd_create(void);
void						wnd_destroy(t_wnd *wnd);

#endif
