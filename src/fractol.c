/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 21:52:12 by cschoen           #+#    #+#             */
/*   Updated: 2019/09/17 21:52:12 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(t_frac *ftl, t_img *img)
{
	t_complex	c;
	t_complex	z;
	t_point		pos;
	double		i;

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
			while (cp_abs_sq(&z) <= 4 && ++i < ftl->iter)
				cp_plus(&c, cp_pow(&z, ftl->pow, &ftl->cp[0]), &z);
			i = i / ftl->iter;
			plot(img, &pos, get_grad_color(&ftl->grad, &i));
		}
	}
}

void	julia(t_frac *ftl, t_img *img)
{
	t_complex	c;
	t_complex	z;
	t_point		pos;
	double		i;

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
			while (cp_abs_sq(&z) <= 4 && ++i < ftl->iter)
				cp_plus(&ftl->k, cp_pow(&z, ftl->pow, &ftl->cp[0]), &z);
			i = i / ftl->iter;
			plot(img, &pos, get_grad_color(&ftl->grad, &i));
		}
	}
}

void	burning_ship(t_frac *ftl, t_img *img)
{
	t_complex	c;
	t_complex	z;
	t_point		pos;
	double		i;

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
			while (cp_abs_sq(&z) <= 4 && ++i < ftl->iter)
				cp_plus(&c, cp_rev_im(cp_abs_im(cp_pow(&z, ftl->pow,
					&ftl->cp[0]), &z), &z), &z);
			i = i / ftl->iter;
			plot(img, &pos, get_grad_color(&ftl->grad, &i));
		}
	}
}

void	mandelbar(t_frac *ftl, t_img *img)
{
	t_complex	c;
	t_complex	z;
	t_point		pos;
	double		i;

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
			while (cp_abs_sq(&z) <= 4 && ++i < ftl->iter)
				cp_plus(&c, cp_rev_im(cp_pow(&z, ftl->pow,
							&ftl->cp[0]), &z), &z);
			i = i / ftl->iter;
			plot(img, &pos, get_grad_color(&ftl->grad, &i));
		}
	}
}

void	celtic(t_frac *ftl, t_img *img)
{
	t_complex	c;
	t_complex	z;
	t_point		pos;
	double		i;

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
			while (cp_abs_sq(&z) <= 4 && ++i < ftl->iter)
				cp_plus(&c, cp_rev_im(cp_abs_re(cp_pow(&z, ftl->pow,
					&ftl->cp[0]), &z), &z), &z);
			i = i / ftl->iter;
			plot(img, &pos, get_grad_color(&ftl->grad, &i));
		}
	}
}
