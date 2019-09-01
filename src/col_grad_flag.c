/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   col_grad_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 19:57:03 by cschoen           #+#    #+#             */
/*   Updated: 2019/09/01 22:26:52 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		color(t_flg *flg, int ac, char **av, int i)
{
	size_t	len;
	int		j;

	flg->flag & F_COL ?
		err_usage("More than 1 color flag", av[0], flg->help) : 0;
	flg->flag |= F_COL;
	flg->args += 4;
	i >= ac - 4 ?
		err_usage("Incorrect use of the color flag", av[0], flg->help) : 0;
	j = -1;
	while (++j < 3)
	{
		len = ft_strlen(av[i + 1 + j]);
		if (!(len == 3 || len == 5 || len == 8))
			err_usage("Incorrect use of the color flag", av[0], flg->help);
		if (!is_hex(av[i + 1 + j]))
			err_usage("Incorrect hex color\nExample: 0xf or 0xf7d or 0xaB322e",
				av[0], flg->help);
		hex_to_rgb(&av[i + 1 + j][2], &flg->grad.col[j]);
	}
}

void		gradient(t_flg *flg, int ac, char **av, int i)
{
	size_t	len;

	flg->flag & F_GRD ?
		err_usage("More than 1 gradient flag", av[0], flg->help) : 0;
	flg->flag |= F_GRD;
	flg->args += 2;
	i >= ac - 2 ?
		err_usage("Incorrect use of the gradient flag\nTry '--gradient 50'",
			av[0], flg->help) : 0;
	len = ft_strlen(av[i + 1]);
	if (len < 1 || len > 3)
		err_usage("Incorrect use of the gradient flag", av[0], flg->help);
	flg->grad.range[1] = ft_atoi(av[i + 1]);
	if (flg->grad.range[1] < 1 || flg->grad.range[1] > 99 ||
		(flg->grad.range[1] < 10 && len != 1) ||
		(flg->grad.range[1] > 9 && len != 2))
		err_usage("Range for gradient must be in [99...1]", av[0], flg->help);
	flg->grad.range[1] = (double)flg->grad.range[1] / 100;
}

static void	valid_col_grad(t_flg *flg, char *arg, char *app_name, int color)
{
	size_t	len;

	len = ft_strlen(arg);
	if (color)
	{
		if (len != 3 && len != 5 && len != 8)
			err_usage("Incorrect use of the color argument of the -X flag",
				app_name, flg->help);
		if (!is_hex(arg))
		{
			ft_putendl(arg);
			err_usage("Incorrect hex color\nExample: 0xf or 0xf7d or 0xabcdef",
				app_name, flg->help);
		}
	}
	else
	{
		if (len < 1 || len > 2)
			err_usage("Incorrect use of the gradient argument of the -X flag",
				app_name, flg->help);
		if (arg[0] < '1' || arg[0] > '9' || (len == 2 && !ft_isdigit(arg[1])))
			err_usage("Range for gradient argument must be in [99...1]",
				app_name, flg->help);
	}
}

static void	col_grad2(t_flg *flg, char **av, int i, int j)
{
	int	col;
	int	grd;

	col = -1;
	grd = -1;
	while (++j < flg->grad.col_cnt * 2 - 2)
	{
		if (!ft_strncmp(av[i + j], "0x", 2) && ++col < flg->grad.col_cnt)
		{
			valid_col_grad(flg, av[i + j], av[0], 1);
			hex_to_rgb(&av[i + j][2], &flg->grad.col[col]);
		}
		else if (++grd < flg->grad.col_cnt - 2)
		{
			valid_col_grad(flg, av[i + j], av[0], 0);
			flg->grad.range[grd + 1] = (double)ft_atoi(av[i + j]) / 100;
			if (grd != 0 && flg->grad.range[grd + 1] >= flg->grad.range[grd])
				err_usage("Gradient arguments should be in descending order",
					av[0], flg->help);
		}
		else
			err_usage("Wrong count of arguments for the -X flag",
				av[0], flg->help);
	}
}

void		col_grad(t_flg *flg, int ac, char **av, int i)
{
	size_t	len;

	flg->flag & F_COL ?
		err_usage("More than 1 color flag", av[0], flg->help) : 0;
	flg->flag & F_GRD ?
		err_usage("More than 1 gradient flag", av[0], flg->help) : 0;
	flg->flag |= F_COL + F_GRD;
	len = (i < ac - 1) ? ft_strlen(av[i + 1]) : 0;
	!len ? err_usage("Incorrect use of the -X flag", av[0], flg->help) : 0;
	if (len > 2 || av[i + 1][0] < '1' || av[i + 1][0] > '9' ||
		(len == 2 && !ft_isdigit(av[i + 1][1])))
		err_usage("Incorrect main argument for the -X flag", av[0], flg->help);
	flg->grad.col_cnt = ft_atoi(av[i + 1]);
	if (flg->grad.col_cnt < 2 || flg->grad.col_cnt > 11)
		err_usage("Range for main argument of -X flag must be in [2...11]",
			av[0], flg->help);
	flg->args += 2 * flg->grad.col_cnt;
	(i >= ac - (2 * flg->grad.col_cnt)) ?
		err_usage("Incorrect use of the -X flag", av[0], flg->help) : 0;
	col_grad2(flg, av, i + 2, -1);
	flg->grad.range[flg->grad.col_cnt - 1] = 0;
}
