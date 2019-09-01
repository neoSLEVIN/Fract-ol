/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 17:33:38 by cschoen           #+#    #+#             */
/*   Updated: 2019/09/01 04:51:39 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	init_mandelbrot(t_frac *ftl)
{
	double	num;

	ftl->min = set_complex((-2.0 + ftl->cam.re) * ftl->zoom,
							(-2.0 - ftl->cam.im) * ftl->zoom);
	ftl->max = set_complex((2.0 + ftl->cam.re) * ftl->zoom,
							(2.0 - ftl->cam.im) * ftl->zoom);
	num = 4 * ftl->zoom / (ftl->size.x - 1);
	ftl->step = set_complex(num, num);
}

void		mandelbrot(t_frac *ftl)
{
	t_complex	c;
	t_complex	z;
	t_point		pos;
	int			i;

	init_mandelbrot(ftl);
	pos.y = -1;
	while (++pos.y < ftl->size.y)
	{
		c.im = ftl->max.im - pos.y * ftl->step.im;
		pos.x = -1;
		while (++pos.x < ftl->size.x)
		{
			c.re = ftl->min.re + pos.x * ftl->step.re;
			z = set_complex(c.re, c.im);
			i = -1;
			while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4 && ++i < ftl->iter)
				z = set_complex(pow(z.re, 2.0) - pow(z.im, 2.0) + c.re,
								2.0 * z.re * z.im + c.im);
			plot(ftl->img, pos,
				get_grad_color(&ftl->grad, 1.0 - (double)i / ftl->iter));
		}
	}
}
