/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 03:06:54 by dbendu            #+#    #+#             */
/*   Updated: 2020/02/25 21:47:07 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <math.h>
# include "data.h"
# include "vector.h"

void		draw_map(t_data *data);
void		rotate_map(t_data *data);
void		put_info(t_data *data);
void		print_map(t_data *data);
void		shift_map(t_data *data, int x, int y);

#endif
