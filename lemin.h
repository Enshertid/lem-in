/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 21:40:28 by dbendu            #+#    #+#             */
/*   Updated: 2020/02/05 12:15:38 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "libft.h"
# include "data.h"
# include "map.h"
# include "animation.h"

int				key_press(int button, t_data *data);
int				mouse_press(int key, int x, int y, t_data *data);
int				mouse_move(int x, int y, t_data *data);
int				mouse_release(int button, int x, int y, t_data *data);
void			draw_line(t_img *img, t_coord a, t_coord b, int color);
int				lemin_exit(t_data *data);

#endif
