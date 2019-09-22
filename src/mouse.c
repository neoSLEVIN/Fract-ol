/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 22:58:33 by cschoen           #+#    #+#             */
/*   Updated: 2019/09/05 23:07:28 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int			change_fractol(t_frac *ftl, int i)
{
	ftl->img->type = ftl->side_imgs[i].type;
	ftl->side_imgs[i].type = ftl->type;
	ftl->type = ftl->img->type;
	draw(ftl, -1);
	return (0);
}

static t_complex	init_shift(t_frac *ftl, int x, int y)
{
	t_complex	shift;

	shift.re = ((double)(x - ftl->img->pos.x) - ((double)ftl->size / 2));
	shift.im = ((double)(y - ftl->img->pos.y) - ((double)ftl->size / 2));
	shift.re /= ftl->size;
	shift.im /= ftl->size;
	shift.re *= ftl->max.re - ftl->min.re;
	shift.im *= ftl->min.im - ftl->max.im;
	return (shift);
}

static void			scroll(t_frac *ftl, _Bool up, t_complex shift, double zoom)
{
	t_complex	new_pos;

	if (((ftl->type != JULIA && ftl->type != NEWTON) || ftl->mem.mouse_zoom) &&
		(up || (!up && ftl->zoom / zoom > 0.05)))
	{
		ftl->cam.re += shift.re * (1.0 - (up ? (1.0 / zoom) : zoom));
		ftl->cam.im += shift.im * (1.0 - (up ? (1.0 / zoom) : zoom));
		ftl->zoom *= up ? zoom : (1.0 / zoom);
	}
	else if (ftl->type == JULIA && !ftl->mem.mouse_zoom)
		ftl->k = c_plus(ftl->cam, shift);
	else if (ftl->type == NEWTON && !ftl->mem.mouse_zoom &&
			ftl->mem.color > 0 && ftl->mem.color <= ftl->root.cnt)
	{
		new_pos = set_complex((ftl->max.re + ftl->min.re) / 2 + shift.re,
							(ftl->max.im + ftl->min.im) / 2 + shift.im);
		ftl->root.roots[ftl->mem.color - 1] = new_pos;
	}
}

int					mouse_click(int button, int x, int y, void *param)
{
	t_frac		*ftl;
	t_complex	shift;
	double		zoom;

	ftl = (t_frac*)param;
	zoom = ZOOM * 1.5;
	if (x >= 500 && y > 500 && ftl->mem.side)
		return (change_fractol(ftl, (x - 500) / 100));
	if (x < ftl->img->pos.x || x > ftl->img->pos.x + ftl->size ||
		y < ftl->img->pos.y || y > ftl->img->pos.y + ftl->size)
		return (0);
	if (button != RIGHT_CLICK && button != SCROLL_CLICK)
		shift = init_shift(ftl, x, y);
	if (button == 1)
		ftl->cam = c_plus(ftl->cam, shift);
	else if (button == RIGHT_CLICK)
		ftl->mem.mouse_hook ^= 1;
	else if (button == SCROLL_CLICK)
		ftl->mem.mouse_zoom ^= 1;
	else if (button == 4 || button == 5)
		scroll(ftl, (button == 4), shift, zoom);
	draw(ftl, -2);
	return (0);
}

int					mouse_move(int x, int y, void *param)
{
	t_frac		*ftl;
	t_complex	shift;
	t_complex	new_pos;

	ftl = (t_frac *)param;
	if (x < ftl->img->pos.x || x > ftl->img->pos.x + ftl->size ||
		y < ftl->img->pos.y || y > ftl->img->pos.y + ftl->size)
		return (0);
	if (ftl->mem.mouse_hook && ftl->type == JULIA)
	{
		shift = init_shift(ftl, x, y);
		ftl->k = c_plus(ftl->cam, shift);
		draw(ftl, -1);
	}
	else if (ftl->mem.mouse_hook && ftl->type == NEWTON &&
			ftl->mem.color > 0 && ftl->mem.color <= ftl->root.cnt)
	{
		shift = init_shift(ftl, x, y);
		new_pos = set_complex((ftl->max.re + ftl->min.re) / 2 + shift.re,
							(ftl->max.im + ftl->min.im) / 2 + shift.im);
		ftl->root.roots[ftl->mem.color - 1] = new_pos;
		draw(ftl, -1);
	}
	return (0);
}
