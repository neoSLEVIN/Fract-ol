/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 23:44:35 by cschoen           #+#    #+#             */
/*   Updated: 2019/09/21 22:32:54 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

static void	print_cmd3(t_frac *ftl)
{
	if (ftl->pow != 2)
	{
		ft_putstr(" -p ");
		if (ftl->type == NEWTON && ftl->pow >= 5)
			ft_putnbr(5);
		else
			ft_putnbr(ftl->pow);
	}
	ft_putstr(" ");
	print_fractol(ftl->type);
	ft_putendl("");
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
	if (ftl->k.re != -0.79 && ftl->type == JULIA)
	{
		ft_putstr(" -k-Re ");
		print_double(ftl->k.re);
	}
	if (ftl->k.im != 0.15 && ftl->type == JULIA)
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
	print_cmd3(ftl);
}
