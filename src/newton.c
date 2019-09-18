/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 23:15:58 by cschoen           #+#    #+#             */
/*   Updated: 2019/09/18 04:08:56 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_rgb	get_root_color(t_rgb *roots, int r, double f)
{
	t_rgb	color;

	color.r = 238 - f * (238 - roots[r].r);
	color.g = 238 - f * (238 - roots[r].g);
	color.b = 238 - f * (238 - roots[r].b);
	return (color);
}

static void	func(t_complex z, t_complex *f, t_complex *df, t_root *root)
{
	t_complex	r;
	t_complex	l;
	int			i;

	i = 0;
	r = c_minus(z, root->roots[0]);
	l = c_minus(z, root->roots[1]);
	while (++i < root->cnt - 1)
	{
		l = c_mult(c_minus(z, root->roots[i + 1]), c_plus(l, r));
		r = c_mult(r, c_minus(z, root->roots[i]));
	}
	*df = c_plus(l, r);
	*f = c_mult(r, c_minus(z, root->roots[root->cnt - 1]));
}

static void	newton_iter(t_frac *ftl, t_complex *z, t_point pos, double i)
{
	t_complex	f;
	t_complex	df;
	t_complex	z0;
	int			r;

	r = -1;
	func(*z, &f, &df, &ftl->root);
	z0 = c_minus(*z, c_divide(c_mult(ftl->root.damping, f), df));
	if (c_abs_sq(c_minus(z0, *z)) < 1e-6)
		while (++r < ftl->root.cnt)
		{
			if (c_abs_sq(c_minus(z0, ftl->root.roots[r])) < 1e-6)
			{
				plot(ftl->img, pos, ftl->flg->flag & F_COL ?
					get_grad_color(&ftl->grad, i / ftl->iter) :
					get_root_color(ftl->root.cols, r, i / ftl->iter));
				return ;
			}
		}
	*z = z0;
}

void	newton(t_frac *ftl)
{
	t_complex	c;
	t_complex	z;
	t_point		pos;
	double		i;

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
			while (++i < ftl->iter)
				newton_iter(ftl, &z, pos, i);
		}
	}
}
