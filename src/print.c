/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 21:40:25 by cschoen           #+#    #+#             */
/*   Updated: 2019/09/21 23:38:06 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

void		draw_info(t_frac *ftl)
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
