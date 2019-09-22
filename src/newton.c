/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 23:15:58 by cschoen           #+#    #+#             */
/*   Updated: 2019/09/23 00:23:48 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	clean_image(t_img *img)
{
	int	x;
	int	y;
	int	*data;

	data = (int*)img->data;
	y = -1;
	while (++y < img->size)
	{
		x = -1;
		while (++x < img->size)
			data[y * img->size + x] = 0;
	}

}

static void	func(t_complex *z, t_complex *f, t_complex *df, t_frac *ftl)
{
	t_complex	r;
	t_complex	l;
	int			i;

	i = 0;
	cp_minus(z, &ftl->root.roots[0], &r);
	cp_minus(z, &ftl->root.roots[1], &l);
	while (++i < ftl->root.cnt - 1)
	{
		cp_mult(cp_minus(z, &ftl->root.roots[i + 1], &ftl->cp[0]),
				cp_plus(&l, &r, &ftl->cp[1]), &l);
		cp_mult(&r, cp_minus(z, &ftl->root.roots[i], &ftl->cp[0]), &r);
	}
	cp_plus(&l, &r, df);
	cp_minus(z, &ftl->root.roots[ftl->root.cnt - 1], f);
	cp_mult(&r, f, f);
}

static void	newton_iter(t_frac *ftl, t_complex *z, t_point *pos, t_img *img)
{
	t_complex	f;
	t_complex	df;
	t_complex	z0;
	int			r;

	r = -1;
	func(z, &f, &df, ftl);
	cp_minus(z, cp_divide(cp_mult(&ftl->root.damping, &f, &z0), &df, &z0), &z0);
	if (cp_abs_sq(cp_minus(&z0, z, &ftl->cp[0])) < EPS)
		while (++r < ftl->root.cnt)
			if (cp_abs_sq(cp_minus(&z0, &ftl->root.roots[r],
									&ftl->cp[0])) < EPS)
				return (plot(img, pos, &ftl->root.cols[r]));
	*z = z0;
}

void	newton(t_frac *ftl, t_img *img)
{
	t_complex	c;
	t_complex	z;
	t_point		pos;
	int			i;

	clean_image(img);
	pos.y = -1;
	while (++pos.y < img->size)
	{
		c.im = ftl->max.im - pos.y * ftl->step.im + ftl->cam.im;
		pos.x = -1;
		while (++pos.x < img->size)
		{
			c.re = ftl->min.re + pos.x * ftl->step.re + ftl->cam.re;
			set_complex_p(c.re, c.im, &z);
			i = -1;
			while (++i < 100)
				newton_iter(ftl, &z, &pos, img);
		}
	}
}
