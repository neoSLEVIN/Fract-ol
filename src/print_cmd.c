/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 23:44:35 by cschoen           #+#    #+#             */
/*   Updated: 2019/09/14 21:50:14 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	print_hex(t_rgb color)
{
	ft_putstr("0x");
	color.r > 255 ? color.r = 511 - color.r : 0;
	color.g > 255 ? color.g = 511 - color.g : 0;
	color.b > 255 ? color.b = 511 - color.b : 0;
	if (color.r / 16 == color.r % 16 && color.g / 16 == color.g % 16 &&
		color.b / 16 == color.b % 16)
	{
		if (color.r == color.g && color.r == color.b)
			print_itoa16(color.r, 0);
		else
		{
			print_itoa16(color.r, 0);
			print_itoa16(color.g, 0);
			print_itoa16(color.b, 0);
		}
	}
	else
	{
		print_itoa16(color.r, 1);
		print_itoa16(color.g, 1);
		print_itoa16(color.b, 1);
	}
}

static void	print_hex_colors(t_grad *grad)
{
	int	i;

	i = -1;
	if (grad->col_cnt != 3)
	{
		ft_putnbr(grad->col_cnt);
		ft_putstr(" ");
	}
	while (++i < grad->col_cnt)
	{
		if (grad->col_cnt != 3 && i != 0 && i != grad->col_cnt - 1)
		{
			ft_putnbr((int)(grad->range[i] * 1000));
			ft_putstr(" ");
		}
		print_hex(grad->col[i]);
		if (i != grad->col_cnt - 1)
			ft_putstr(" ");
	}
}

static int	rgbcmp(t_rgb rgb1, t_rgb rgb2)
{
	rgb1.r > 255 ? rgb1.r = 511 - rgb1.r : 0;
	rgb1.g > 255 ? rgb1.g = 511 - rgb1.g : 0;
	rgb1.b > 255 ? rgb1.b = 511 - rgb1.b : 0;
	rgb2.r > 255 ? rgb2.r = 511 - rgb2.r : 0;
	rgb2.g > 255 ? rgb2.g = 511 - rgb2.g : 0;
	rgb2.b > 255 ? rgb2.b = 511 - rgb2.b : 0;
	return (!(rgb1.r == rgb2.r || rgb1.g == rgb2.g || rgb1.b == rgb2.b));
}

static void	print_cmd2(t_frac *ftl)
{
	if (ftl->iter != 100)
	{
		ft_putstr(" -m ");
		ft_putnbr(ftl->iter);
	}
	if (ftl->cam.re != 0)
	{
		ft_putstr(" -Re ");
		print_double(ftl->cam.re);
	}
	if (ftl->cam.im != 0)
	{
		ft_putstr(" -Im ");
		print_double(ftl->cam.im);
	}
	if (ftl->k.re != -0.79)
	{
		ft_putstr(" -k-Re ");
		print_double(ftl->k.re);
	}
	if (ftl->k.im != 0.15)
	{
		ft_putstr(" -k-Im ");
		print_double(ftl->k.im);
	}
}

void		print_cmd(t_frac *ftl)
{
	ft_putstr(ftl->flg->app);
	if (ftl->size != 500)
	{
		ft_putstr(" -s ");
		ft_putnbr(ftl->size);
	}
	if (ftl->grad.col_cnt == 3 && (rgbcmp(ftl->grad.col[0], set_rgb(0, 0, 0)) ||
		rgbcmp(ftl->grad.col[1], set_rgb(136, 136, 136)) ||
		rgbcmp(ftl->grad.col[2], set_rgb(255, 255, 255))))
	{
		ft_putstr(" -c ");
		print_hex_colors(&ftl->grad);
	}
	if (ftl->grad.col_cnt == 3 && (int)(ftl->grad.range[1] * 1000) != 500)
	{
		ft_putstr(" -g ");
		ft_putnbr((int)(ftl->grad.range[1] * 1000));
	}
	if (ftl->grad.col_cnt != 3)
	{
		ft_putstr(" -X ");
		print_hex_colors(&ftl->grad);
	}
	print_cmd2(ftl);
	print_fractol(ftl->type, " ", "\n");
}
