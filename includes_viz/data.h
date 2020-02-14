/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 22:11:00 by dbendu            #+#    #+#             */
/*   Updated: 2020/02/14 04:14:07 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

# include "animation.h"
# include "libft.h"
# include "graph.h"
# include "hashtable.h"
# include "wnd.h"

typedef struct			s_angles
{
	int					x_angle;
	int					y_angle;
	int					z_angle;
	float				cosx;
	float				sinx;
	float				cosy;
	float				siny;
	float				cosz;
	float				sinz;
}						t_angles;

typedef struct			s_appearance
{
	t_angles			angles;
	t_bool				show_hints;
	t_bool				show_rooms_names;
}						t_appearance;

typedef struct			s_mouse
{
	t_bool				is_left_button_active;
	t_bool				is_right_button_active;
	int					x;
	int					y;
}						t_mouse;

typedef struct			s_data
{
	t_coord				camera;
	uint64_t			flags;
	t_graph				graph;
	t_wnd				wnd;
	t_mouse				mouse;
	t_animation			animation;
	t_appearance		appearance;
}						t_data;

t_data					data_create(char **argv);
void					data_destroy(t_data *data);

#endif
