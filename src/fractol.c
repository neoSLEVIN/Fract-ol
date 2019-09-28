/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 21:52:12 by cschoen           #+#    #+#             */
/*   Updated: 2019/09/28 14:01:21 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(t_frac *ftl, int ftl_id, t_point limits, t_img *img)
{
	t_complex	c;
	t_complex	z;
	t_point		pos;
	double		i;

	pos.y = limits.x - 1;
	while (++pos.y < limits.y)
	{
		c.im = ftl->max.im - pos.y * ftl->step.im + ftl->cam.im;
		pos.x = -1;
		while (++pos.x < img->size)
		{
			c.re = ftl->min.re + pos.x * ftl->step.re + ftl->cam.re;
			set_complex_p(c.re, c.im, &z);
			i = -1;
			while (cp_abs_sq(&z) <= 4 && ++i < ftl->iter)
				cp_plus(&c, cp_pow(&z, ftl->pow, &ftl->cp[ftl_id]), &z);
			i = i / ftl->iter;
			plot(img, &pos, get_grad_color(&ftl->grad, &i, ftl_id));
		}
	}
}

void	julia(t_frac *ftl, int ftl_id, t_point limits, t_img *img)
{
	t_complex	c;
	t_complex	z;
	t_point		pos;
	double		i;

	pos.y = limits.x - 1;
	while (++pos.y < limits.y)
	{
		c.im = ftl->max.im - pos.y * ftl->step.im + ftl->cam.im;
		pos.x = -1;
		while (++pos.x < img->size)
		{
			c.re = ftl->min.re + pos.x * ftl->step.re + ftl->cam.re;
			set_complex_p(c.re, c.im, &z);
			i = -1;
			while (cp_abs_sq(&z) <= 4 && ++i < ftl->iter)
				cp_plus(&ftl->k, cp_pow(&z, ftl->pow, &ftl->cp[ftl_id]), &z);
			i = i / ftl->iter;
			plot(img, &pos, get_grad_color(&ftl->grad, &i, ftl_id));
		}
	}
}

void	burning_ship(t_frac *ftl, int ftl_id, t_point limits, t_img *img)
{
	t_complex	c;
	t_complex	z;
	t_point		pos;
	double		i;

	pos.y = limits.x - 1;
	while (++pos.y < limits.y)
	{
		c.im = ftl->max.im - pos.y * ftl->step.im + ftl->cam.im;
		pos.x = -1;
		while (++pos.x < img->size)
		{
			c.re = ftl->min.re + pos.x * ftl->step.re + ftl->cam.re;
			set_complex_p(c.re, c.im, &z);
			i = -1;
			while (cp_abs_sq(&z) <= 4 && ++i < ftl->iter)
				cp_plus(&c, cp_rev_im(cp_pow(cp_abs_im(cp_abs_re(&z, &z), &z),
						ftl->pow, &ftl->cp[ftl_id]), &z), &z);
			i = i / ftl->iter;
			plot(img, &pos, get_grad_color(&ftl->grad, &i, ftl_id));
		}
	}
}

void	mandelbar(t_frac *ftl, int ftl_id, t_point limits, t_img *img)
{
	t_complex	c;
	t_complex	z;
	t_point		pos;
	double		i;

	pos.y = limits.x - 1;
	while (++pos.y < limits.y)
	{
		c.im = ftl->max.im - pos.y * ftl->step.im + ftl->cam.im;
		pos.x = -1;
		while (++pos.x < img->size)
		{
			c.re = ftl->min.re + pos.x * ftl->step.re + ftl->cam.re;
			set_complex_p(c.re, c.im, &z);
			i = -1;
			while (cp_abs_sq(&z) <= 4 && ++i < ftl->iter)
				cp_plus(&c, cp_rev_im(cp_pow(&z, ftl->pow,
							&ftl->cp[ftl_id]), &z), &z);
			i = i / ftl->iter;
			plot(img, &pos, get_grad_color(&ftl->grad, &i, ftl_id));
		}
	}
}

void	celtic(t_frac *ftl, int ftl_id, t_point limits, t_img *img)
{
	t_complex	c;
	t_complex	z;
	t_point		pos;
	double		i;

	pos.y = limits.x - 1;
	while (++pos.y < limits.y)
	{
		c.im = ftl->max.im - pos.y * ftl->step.im + ftl->cam.im;
		pos.x = -1;
		while (++pos.x < img->size)
		{
			c.re = ftl->min.re + pos.x * ftl->step.re + ftl->cam.re;
			set_complex_p(c.re, c.im, &z);
			i = -1;
			while (cp_abs_sq(&z) <= 4 && ++i < ftl->iter)
				cp_plus(&c, cp_rev_im(cp_abs_re(cp_pow(&z, ftl->pow,
					&ftl->cp[ftl_id]), &z), &z), &z);
			i = i / ftl->iter;
			plot(img, &pos, get_grad_color(&ftl->grad, &i, ftl_id));
		}
	}
}
