/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 21:40:28 by dbendu            #+#    #+#             */
/*   Updated: 2020/02/26 16:54:07 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "libft.h"
# include "data.h"
# include "map.h"
# include "animation.h"

# define GNL_BUFF		1024

int				key_press(int button, t_data *data);
int				mouse_press(int key, int x, int y, t_data *data);
int				mouse_move(int x, int y, t_data *data);
int				mouse_release(int button, int x, int y, t_data *data);
void			draw_line(t_img *img, t_coord a, t_coord b, int color);
int				lemin_exit(t_data *data);
int				get_next_line(const int fd, char **line);

void			ft_free_all(void);
void			ft_my_free(void *ptr);
void			*ft_malloc(size_t size);

#endif
