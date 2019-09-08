/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 21:40:25 by cschoen           #+#    #+#             */
/*   Updated: 2019/09/08 23:46:42 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		print_fractol(t_type type)
{
	if (type == MANDELBROT)
		ft_putendl("Mandelbrot");
	else if (type == JULIA)
		ft_putendl("Julia");
}

static void	print_color(t_rgb *color)
{
	ft_putstr("{ ");
	ft_putnbr(color->r > 255 ? 511 - color->r : color->r);
	ft_putstr(", ");
	ft_putnbr(color->g > 255 ? 511 - color->g : color->g);
	ft_putstr(", ");
	ft_putnbr(color->b > 255 ? 511 - color->b : color->b);
	ft_putendl(" }");
}

void		print_double(double num)
{
	char	*s;

	num < 0 ? ft_putstr("-") : 0;
	num < 0 ? num *= -1 : 0;
	ft_putnbr((int)num);
	num = (num - (int)num) * 100000000;
	if (!(s = ft_itoa((int)num)))
		error("No memory allocated for print info.");
	num = (num - (int)num) * 10000000;
	if ((int)num != 0)
	{
		ft_putstr(".");
		write(1, "00000000", (size_t)(8 - ft_strlen(s)));
		ft_putstr(s);
		ft_strdel(&s);
		if (!(s = ft_itoa((int)num)))
			error("No memory allocated for print info.");
	}
	if (ft_strlen(s) == 1 || *s == '0')
		return ;
	(int)num == 0 ? ft_putstr(".") : 0;
	write(1, "00000000", (size_t)(((int)num == 0 ? 8 : 7) - ft_strlen(s)));
	ft_putstr(s);
	ft_strdel(&s);
}

void		print_info(t_frac *ftl, int i)
{
	print_fractol(ftl->type);
	ft_putendl("  Grad:\tColor:");
	while (++i < ftl->grad.col_cnt)
	{
		ft_putstr("  ");
		ft_putnbr((int)(ftl->grad.range[i] * 1000));
		ft_putstr("\t");
		print_color(&ftl->grad.col[i]);
	}
	ft_putstr("  Center:\n    Re: ");
	print_double(ftl->cam.re);
	ft_putstr("\n    Im: ");
	print_double(ftl->cam.im);
	if (ftl->type == JULIA)
	{
		ft_putstr("\n  k:\n    Re: ");
		print_double(ftl->k.re);
		ft_putstr("\n    Im: ");
		print_double(ftl->k.im);
	}
	ft_putstr("\n  Max iter: ");
	ft_putnbr(ftl->iter);
	ft_putendl("\n");
}
