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
			while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4 && ++i < ftl->iter)
				z = set_complex(pow(z.re, 2.0) - pow(z.im, 2.0) + c.re,
								2.0 * z.re * z.im + c.im);
			plot(ftl->img, pos, get_grad_color(ftl, i / ftl->iter));
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
			while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4 && ++i < ftl->iter)
				z = set_complex(pow(z.re, 2.0) - pow(z.im, 2.0) + ftl->k.re,
								2.0 * z.re * z.im + ftl->k.im);
			plot(ftl->img, pos, get_grad_color(ftl, i / ftl->iter));
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
			while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4 && ++i < ftl->iter)
				z = set_complex(pow(z.re, 2.0) - pow(z.im, 2.0) + c.re,
								-fabs(2.0 * z.re * z.im) + c.im);
			plot(ftl->img, pos, get_grad_color(ftl, i / ftl->iter));
		}
	}
}

void	fractol_4(t_frac *ftl)
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
			while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4 && ++i < ftl->iter)
				z = set_complex(pow(z.re, 2.0) - pow(z.im, 2.0) + c.re,
								-2.0 * z.re * z.im + c.im);
			plot(ftl->img, pos, get_grad_color(ftl, i / ftl->iter));
		}
	}
}

void	fractol_5(t_frac *ftl)
{
	t_complex	c;
	t_complex	z;
	t_point		pos;
	double		i;
	t_complex	com_1;
	t_complex	com_2;
	t_complex	com_3;

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
			{
				com_1 = set_complex(sin(z.re) * cosh(z.im), cos(z.re) * sinh(z.im));
				com_2 = set_complex(cos(z.re) * cosh(z.im), -sin(z.re) * sinh(z.im));
				com_3.re = (com_1.re * com_2.re - com_1.im * com_2.im) /
							(pow(com_2.re, 2.0) + pow(com_2.im, 2.0));
				com_3.im = (com_1.im * com_2.re + com_1.re * com_2.im) /
							(pow(com_2.re, 2.0) + pow(com_2.im, 2.0));
				z = set_complex(z.re + com_3.re - c.re, z.im + com_3.im + c.im);
			}
			plot(ftl->img, pos, get_grad_color(ftl, i / ftl->iter));
		}
	}
}

void	fractol_6(t_frac *ftl)
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
			while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4 && ++i < ftl->iter)
				z = set_complex(pow(z.re, 3.0) + c.re,
								-pow(z.im, 3.0) + c.im);
			plot(ftl->img, pos, get_grad_color(ftl, i / ftl->iter));
		}
	}
}
