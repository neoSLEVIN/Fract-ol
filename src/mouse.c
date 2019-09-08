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

static t_complex	init_shift(t_frac *ftl, int x, int y)
{
	t_complex	shift;

	shift.re = ((double)x - ((double)ftl->size / 2)) / ftl->size;
	shift.im = ((double)y - ((double)ftl->size / 2)) / ftl->size;
	shift.re *= ftl->max.re - ftl->min.re;
	shift.im *= ftl->max.re - ftl->min.re;
	return (shift);
}

int					mouse_click(int button, int x, int y, void *param)
{
	t_frac		*ftl;
	t_complex	shift;
	double		zoom;

	ftl = (t_frac*)param;
	zoom = ZOOM * 1.5;
	shift = init_shift(ftl, x, y);
	if (button == 1)
		ftl->cam = set_complex(ftl->cam.re + shift.re, ftl->cam.im - shift.im);
	else if (ftl->type != JULIA &&
		(button == 4 || (button == 5 && ftl->zoom / zoom > 0.05)))
	{
		ftl->cam.re += shift.re * (1.0 - ((button == 4) ? (1.0 / zoom) : zoom));
		ftl->cam.im -= shift.im * (1.0 - ((button == 4) ? (1.0 / zoom) : zoom));
		ftl->zoom *= (button == 4) ? zoom : (1.0 / zoom);
	}
	else if (ftl->type == JULIA && (button == 4 || button == 5))
		ftl->k = set_complex(ftl->cam.re + shift.re, ftl->cam.im - shift.im);
	else if (ftl->type == JULIA && button == 2)
		ftl->mem.mouse_hook ^= 1;
	draw(ftl);
	return (0);
}

int					mouse_move(int x, int y, void *param)
{
	t_frac		*ftl;
	t_complex	shift;

	ftl = (t_frac *)param;
	if (ftl->mem.mouse_hook)
	{
		shift = init_shift(ftl, x, y);
		ftl->k = set_complex(ftl->cam.re + shift.re, ftl->cam.im - shift.im);
		draw(ftl);
	}
	return (0);
}
