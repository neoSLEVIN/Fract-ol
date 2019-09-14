/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 17:33:38 by cschoen           #+#    #+#             */
/*   Updated: 2019/09/05 22:54:11 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_complex	init_z(t_frac *ftl, t_complex z, t_complex c)
{
	if (ftl->type == JULIA)
		return (set_complex(pow(z.re, 2.0) - pow(z.im, 2.0) + ftl->k.re,
							2.0 * z.re * z.im + ftl->k.im));
	else if (ftl->type == BURNING_SHIP)
		return (set_complex(pow(z.re, 2.0) - pow(z.im, 2.0) + c.re,
							-fabs(2.0 * z.re * z.im) + c.im));
	else
		return (set_complex(pow(z.re, 2.0) - pow(z.im, 2.0) + c.re,
							2.0 * z.re * z.im + c.im));
}

static void			init_edge(t_frac *ftl)
{
	double	step;

	ftl->min = set_complex((-2.0 / ftl->zoom), (-2.0 / ftl->zoom));
	ftl->max = set_complex((2.0 / ftl->zoom), (2.0 / ftl->zoom));
	step = 4.0 / ftl->zoom / (ftl->size - 1);
	ftl->step = set_complex(step, step);
}

void				draw_fractol(t_frac *ftl)
{
	t_complex	c;
	t_complex	z;
	t_point		pos;
	double		i;

	init_edge(ftl);
	pos.y = -1;
	while (++pos.y < ftl->size)
	{
		c.im = ftl->max.im - pos.y * ftl->step.im + ftl->cam.im;
		pos.x = -1;
		while (++pos.x < ftl->size)
		{
			c.re = ftl->min.re + pos.x * ftl->step.re + ftl->cam.re;
			z = set_complex(c.re, c.im);
			i = -1;
			while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4 && ++i < ftl->iter)
				z = init_z(ftl, z, c);
			plot(ftl->img, pos, get_grad_color(ftl, i / ftl->iter));
		}
	}
}
