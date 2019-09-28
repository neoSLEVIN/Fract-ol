/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 23:15:58 by cschoen           #+#    #+#             */
/*   Updated: 2019/09/28 15:51:35 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	clean_image(t_img *img, t_point limits)
{
	int	x;
	int	y;
	int	*data;

	data = (int*)img->data;
	y = limits.x - 1;
	while (++y < limits.y)
	{
		x = -1;
		while (++x < img->size)
			data[y * img->size + x] = 0;
	}
}

static void	func(t_complex *z, t_newton *f_df, t_frac *ftl, int ftl_id)
{
	t_complex	r;
	t_complex	l;
	int			i;

	i = 0;
	cp_minus(z, &ftl->root.roots[0], &r);
	cp_minus(z, &ftl->root.roots[1], &l);
	while (++i < ftl->root.cnt - 1)
	{
		cp_mult(cp_minus(z, &ftl->root.roots[i + 1],
			&ftl->cp[T_CNT * 3 + ftl_id]), cp_plus(&l, &r,
			&ftl->cp[T_CNT * 2 + ftl_id]), &l);
		cp_mult(&r, cp_minus(z, &ftl->root.roots[i],
			&ftl->cp[T_CNT + ftl_id]), &r);
	}
	cp_plus(&l, &r, &f_df->c2);
	cp_minus(z, &ftl->root.roots[ftl->root.cnt - 1], &f_df->c1);
	cp_mult(&r, &f_df->c1, &f_df->c1);
}

static void	newton_iter(t_frac *ftl, t_newton *n, t_img *img, double *i)
{
	t_newton	f_df;
	t_complex	z0;
	int			r;

	r = -1;
	func(&n->c2, &f_df, ftl, n->ftl_id);
	cp_minus(&n->c2, cp_divide(cp_mult(&ftl->root.damping, &f_df.c1, &z0),
								&f_df.c2, &z0), &z0);
	if (cp_abs_sq(cp_minus(&z0, &n->c2, &ftl->cp[T_CNT * 5 + n->ftl_id])) < EPS)
		while (++r < ftl->root.cnt)
			if (cp_abs_sq(cp_minus(&z0, &ftl->root.roots[r],
				&ftl->cp[T_CNT * 4 + n->ftl_id])) < EPS || (int)*i == N_ITER)
			{
				*i = *i / N_ITER;
				plot(img, &n->pos, true_color(ftl->root.cols[r],
					set_rgb(0, 0, 0), i, &ftl->grad.tmp[n->ftl_id]));
				*i = N_ITER;
				return ;
			}
	n->c2 = z0;
}

void		newton(t_frac *ftl, int ftl_id, t_point limits, t_img *img)
{
	t_newton	n;
	double		i;

	n.ftl_id = ftl_id;
	clean_image(img, limits);
	n.pos.y = limits.x - 1;
	while (++n.pos.y < limits.y)
	{
		n.c1.im = ftl->max.im - n.pos.y * ftl->step.im + ftl->cam.im;
		n.pos.x = -1;
		while (++n.pos.x < img->size)
		{
			n.c1.re = ftl->min.re + n.pos.x * ftl->step.re + ftl->cam.re;
			set_complex_p(n.c1.re, n.c1.im, &n.c2);
			i = -1;
			while (++i < N_ITER)
				newton_iter(ftl, &n, img, &i);
		}
	}
}
