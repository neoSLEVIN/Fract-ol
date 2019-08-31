/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 17:33:38 by cschoen           #+#    #+#             */
/*   Updated: 2019/09/01 01:05:49 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		mandelbrot(t_frac *ftl)
{
	t_complex	min;
	t_complex	max;
	t_complex	factor;
	t_complex	c;
	t_complex	z;
	t_point		p;
	double		t;
	int			i;

	min = set_complex(-2.0, -2.0);
	max.re = 2.0;
	max.im = min.im + (max.re - min.re) * ftl->size.x / ftl->size.y;
	factor = set_complex((max.re - min.re) / (ftl->size.x - 1),
						(max.im - min.im) / (ftl->size.y - 1));
	p.y = -1;
	while (++p.y < ftl->size.y)
	{
		c.im = max.im - p.y * factor.im;
		p.x = -1;
		while (++p.x < ftl->size.x)
		{
			c.re = min.re + p.x * factor.re;
			z = set_complex(c.re, c.im);
			i = -1;
			while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4 && ++i < ftl->iter)
				z = set_complex(pow(z.re, 2.0) - pow(z.im, 2.0) + c.re,
								2.0 * z.re * z.im + c.im);
			t = (double)i / (double)ftl->iter;
			plot(ftl->img, get_grad_color(&ftl->grad, t), p);
		}
	}
}
