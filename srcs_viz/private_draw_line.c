/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   private_draw_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 21:40:41 by dbendu            #+#    #+#             */
/*   Updated: 2020/02/14 04:35:49 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private_map.h"

static void		brez_vert_gradient(t_img *img, t_coord *a, t_coord *b,
									int color)
{
	const int	dx = b->x - a->x > 0 ? 1 : -1;
	const int	dy = b->y - a->y > 0 ? 1 : -1;
	const int	lenx = abs(b->x - a->x);
	const int	leny = abs(b->y - a->y);
	int			needful[2];

	needful[1] = -leny;
	needful[0] = ft_max(lenx, leny) + 1;
	while (needful[0]--)
	{
		if (a->x >= 0 && a->y >= 0 && a->x <= MAX_X && a->y <= MAX_Y)
			*(uint32_t*)(img->img + a->y * img->size_line + a->x * img->bytes) =
																		color;
		a->y += dy;
		needful[1] += 2 * lenx;
		if (needful[1] > 0)
		{
			needful[1] -= 2 * leny;
			a->x += dx;
		}
	}
}

static void		brez_hor_gradiend(t_img *img, t_coord *a, t_coord *b,
									int color)
{
	const int	dx = b->x - a->x > 0 ? 1 : -1;
	const int	dy = b->y - a->y > 0 ? 1 : -1;
	const int	lenx = abs(b->x - a->x);
	const int	leny = abs(b->y - a->y);
	int			needful[2];

	needful[1] = -lenx;
	needful[0] = ft_max(lenx, leny) + 1;
	while (needful[0]--)
	{
		if (a->x >= 0 && a->y >= 0 && a->x <= MAX_X && a->y <= MAX_Y)
			*(uint32_t*)(img->img + a->y * img->size_line + a->x * img->bytes) =
																		color;
		a->x += dx;
		needful[1] += 2 * leny;
		if (needful[1] > 0)
		{
			needful[1] -= 2 * lenx;
			a->y += dy;
		}
	}
}

void			draw_line(t_img *img, t_coord a, t_coord b, int color)
{
	int lenx;
	int leny;

	if ((a.x < 0 && b.x < 0) || (a.y < 0 && b.y < 0) ||
		(a.x > MAX_X && b.x > MAX_X) || (a.y > MAX_Y && b.y > MAX_Y))
		return ;
	lenx = abs(b.x - a.x);
	leny = abs(b.y - a.y);
	if (lenx > leny)
		brez_hor_gradiend(img, &a, &b, color);
	else
		brez_vert_gradient(img, &a, &b, color);
	return ;
}
