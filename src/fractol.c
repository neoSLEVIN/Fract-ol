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

void	mandelbrot(t_frac *ftl)
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
			while (c_abs_sq(z) <= 4 && ++i < ftl->iter)
				z = c_plus(c_pow(z, ftl->pow), c);
			plot(ftl->img, pos, get_grad_color(&ftl->grad, i / ftl->iter));
		}
	}
}

void	julia(t_frac *ftl)
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
			while (c_abs_sq(z) <= 4 && ++i < ftl->iter)
				z = c_plus(c_pow(z, ftl->pow), ftl->k);
			plot(ftl->img, pos, get_grad_color(&ftl->grad, i / ftl->iter));
		}
	}
}

void	burning_ship(t_frac *ftl)
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
			while (c_abs_sq(z) <= 4 && ++i < ftl->iter)
				z = c_plus(c_rev_im(c_abs_im(c_pow(z, ftl->pow))), c);
			plot(ftl->img, pos, get_grad_color(&ftl->grad, i / ftl->iter));
		}
	}
}

void	mandelbar(t_frac *ftl)
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
			while (c_abs_sq(z) <= 4 && ++i < ftl->iter)
				z = c_plus(c_rev_im(c_pow(z, ftl->pow)), c);
			plot(ftl->img, pos, get_grad_color(&ftl->grad, i / ftl->iter));
		}
	}
}

void	celtic(t_frac *ftl)
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
			while (c_abs_sq(z) <= 4 && ++i < ftl->iter)
				z = c_plus(c_rev_im(c_abs_re(c_pow(z, ftl->pow))), c);
			plot(ftl->img, pos, get_grad_color(&ftl->grad, i / ftl->iter));
		}
	}
}
