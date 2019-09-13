/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 23:44:35 by cschoen           #+#    #+#             */
/*   Updated: 2019/09/13 02:21:47 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
/*
static void	print_hex(int num)
{
	num++;
}
*/
static void	print_hex_colors(t_grad *grad)
{
	int	i;

	i = -1;
	if (grad)
	while (++i < 3)
	{
		ft_putstr("0x");

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

void		print_cmd(t_frac *ftl)
{
	ft_putstr(ftl->flg->app);
	if (ftl->size != 500)
	{
		ft_putstr(" -s ");
		ft_putnbr(ftl->size);
	}
	if (ftl->grad.col_cnt == 3 &&
		rgbcmp(ftl->grad.col[0], set_rgb(255, 255, 255)) &&
		rgbcmp(ftl->grad.col[1], set_rgb(136, 136, 136)) &&
		rgbcmp(ftl->grad.col[2], set_rgb(0, 0, 0)))
	{
		ft_putstr(" -c ");
		print_hex_colors(&ftl->grad);
	}
}
