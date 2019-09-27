/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 23:15:58 by cschoen           #+#    #+#             */
/*   Updated: 2019/09/28 00:43:31 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	clean_image(t_img *img)
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
/*
static void	func(t_complex *z, t_complex *f, t_complex *df, t_frac *ftl, t_img *img)
{
	t_complex	r;
	t_complex	l;
	int			i;

	i = 0;
	cp_minus(z, &ftl->root.roots[0], &r);
	cp_minus(z, &ftl->root.roots[1], &l);
	while (++i < ftl->root.cnt - 1)
	{
		cp_mult(cp_minus(z, &ftl->root.roots[i + 1], &ftl->cp[img->t_max * 3 + img->t_id]),
				cp_plus(&l, &r, &ftl->cp[img->t_max + img->t_id]), &l);
		cp_mult(&r, cp_minus(z, &ftl->root.roots[i], &ftl->cp[img->t_max * 2 + img->t_id]), &r);
	}
	cp_plus(&l, &r, df);
	cp_minus(z, &ftl->root.roots[ftl->root.cnt - 1], f);
	cp_mult(&r, f, f);
}

static void	newton_iter(t_frac *ftl, t_complex *z, t_point *pos, t_img *img, double *i)
{
	t_complex	f;
	t_complex	df;
	t_complex	z0;
	int			r;

	r = -1;
	func(z, &f, &df, ftl, img);
	cp_minus(z, cp_divide(cp_mult(&ftl->root.damping, &f, &z0), &df, &z0), &z0);
	if (cp_abs_sq(cp_minus(&z0, z, &ftl->cp[img->t_max * 5 + img->t_id])) < EPS)
		while (++r < ftl->root.cnt)
			if (cp_abs_sq(cp_minus(&z0, &ftl->root.roots[r],
								   &ftl->cp[img->t_max * 4 + img->t_id])) < EPS ||
				(int)*i == N_ITER)
			{
				*i = *i / N_ITER;
				plot(img, pos, true_color(ftl->root.cols[r],
									set_rgb(0, 0, 0), i, &ftl->grad.tmp[img->t_id - 1]));
				*i = N_ITER;
				return ;
			}
	*z = z0;
}

void	*newton(void *th_img)
{
	t_img	*img;
	t_complex	c;
	t_complex	z;
	t_point		pos;
	double		i;

	img = (t_img*)th_img;
	pos.y = img->y_min - 1;
	while (++pos.y < img->y_max)
	{
		c.im = ((t_frac*)img->ftl)->max.im - pos.y * ((t_frac*)img->ftl)->step.im + ((t_frac*)img->ftl)->cam.im;
		pos.x = -1;
		while (++pos.x < img->size)
		{
			c.re = ((t_frac*)img->ftl)->min.re + pos.x * ((t_frac*)img->ftl)->step.re + ((t_frac*)img->ftl)->cam.re;
			set_complex_p(c.re, c.im, &z);
			i = -1;
			while (++i < N_ITER)
				newton_iter(((t_frac *)img->ftl), &z, &pos, img, &i);
		}
	}
	return (th_img);
}
*/
