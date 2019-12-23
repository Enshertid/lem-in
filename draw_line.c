/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <dbendu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 21:24:13 by dbendu            #+#    #+#             */
/*   Updated: 2019/12/17 15:45:07 by dbendu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vizu.h"


static void		set_colors(t_point *a, t_point *b, float shift[3])
{
	float gip;

	gip = sqrt(pow(a->x - b->x, 2) + pow(a->y - b->y, 2));
	shift[0] = fabsf(a->red - b->red) / gip;
	shift[1] = fabsf(a->green - b->green) / gip;
	shift[2] = fabsf(a->blue - b->blue) / gip;
	if (a->red > b->red)
		shift[0] = -shift[0];
	if (a->green > b->green)
		shift[1] = -shift[1];
	if (a->blue > b->blue)
		shift[2] = -shift[2];
}

static void		brez_vert_gradient(t_image *img, t_point *a, t_point *b)
{
	const int	dx = b->x - a->x > 0 ? 1 : -1;
	const int	dy = b->y - a->y > 0 ? 1 : -1;
	const int	lenx = ft_abs(b->x - a->x);
	const int	leny = ft_abs(b->y - a->y);
	int			iters;
	int			d;
	float		shift[3];

	set_colors(a, b, shift);
	d = -leny;
	iters = ft_max(lenx, leny) + 1;
	while (iters--)
	{
		if (a->x >= 0 && a->y >= 0 && a->x <= MAX_X && a->y <= MAX_Y)
			*(t_uint32*)(img->img + a->y * img->size_line + a->x * img->bytes) =
					((int)a->red << 16) + ((int)a->green << 8) + a->blue;
		a->red += shift[0];
		a->green += shift[1];
		a->blue += shift[2];
		a->y += dy;
		d += 2 * lenx;
		if (d > 0)
		{
			d -= 2 * leny;
			a->x += dx;
		}
	}
}

static void		brez_hor_gradiend(t_image *img, t_point *a, t_point *b)
{
	const int	dx = b->x - a->x > 0 ? 1 : -1;
	const int	dy = b->y - a->y > 0 ? 1 : -1;
	const int	lenx = ft_abs(b->x - a->x);
	const int	leny = ft_abs(b->y - a->y);
	int			iters;
	int			d;
	float		shift[3];

	set_colors(a, b, shift);
	d = -lenx;
	iters = ft_max(lenx, leny) + 1;
	while (iters--)
	{
		if (a->x >= 0 && a->y >= 0 && a->x <= MAX_X && a->y <= MAX_Y)
			*(t_uint32*)(img->img + a->y * img->size_line + a->x * img->bytes) =
					((int)a->red << 16) + ((int)a->green << 8) + a->blue;
		a->red += shift[0];
		a->green += shift[1];
		a->blue += shift[2];
		a->x += dx;
		d += 2 * leny;
		if (d > 0)
		{
			d -= 2 * lenx;
			a->y += dy;
		}
	}
}

void			draw_line(t_image *img, t_point a, t_point b)
{
	int lenx;
	int leny;

	if ((a.x < 0 && b.x < 0) || (a.y < 0 && b.y < 0) ||
		(a.x > MAX_X && b.x > MAX_X) || (a.y > MAX_Y && b.y > MAX_Y))
		return ;
	lenx = ft_abs(b.x - a.x);
	leny = ft_abs(b.y - a.y);
	if (lenx > leny)
		brez_hor_gradiend(img, &a, &b);
	else
		brez_vert_gradient(img, &a, &b);
	return ;
}