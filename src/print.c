/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 21:40:25 by cschoen           #+#    #+#             */
/*   Updated: 2019/09/20 21:04:11 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		print_fractol(t_type type)
{
	if (type == MANDELBROT)
		ft_putendl("Mandelbrot");
	else if (type == JULIA)
		ft_putendl("Julia");
	else if (type == BURNING_SHIP)
		ft_putendl("Burning_Ship");
	else if (type == MANDELBAR)
		ft_putendl("Mandelbar");
	else if (type == CELTIC)
		ft_putendl("Celtic");
	else if (type == NEWTON)
		ft_putendl("Newton");
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
		return (ft_strdel(&s));
	(int)num == 0 ? ft_putstr(".") : 0;
	write(1, "00000000", (size_t)(((int)num == 0 ? 8 : 7) - ft_strlen(s)));
	ft_putstr(s);
	ft_strdel(&s);
}

static void	print_info2(t_frac *ftl, int i)
{
	if (ftl->type != NEWTON)
	{
		ft_putendl("  Grad:\tColor:");
		while (++i < ftl->grad.col_cnt)
		{
			ft_putstr("  ");
			ft_putnbr((int)(ftl->grad.range[i] * 1000));
			ft_putstr("\t");
			print_color(&ftl->grad.col[i]);
		}
	}
	else
		while (++i < ftl->root.cnt)
		{
			ft_putstr("  ");
			ft_putnbr(i + 1);
			ft_putstr(")\n   Re: ");
			print_double(ftl->root.roots[i].re);
			ft_putstr("\n   Im: ");
			print_double(ftl->root.roots[i].im);
			ft_putstr("\n   Color: ");
			print_color(&ftl->root.cols[i]);
		}
}

void		print_info(t_frac *ftl)
{
	print_fractol(ftl->type);
	print_info2(ftl, -1);
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
	ft_putendl("");
	ftl->type == NEWTON ? ft_putstr("  Roots: ") : ft_putstr("  Z-Power: ");
	ft_putnbr(ftl->pow);
	ft_putendl("\n");
}
