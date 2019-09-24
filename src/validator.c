/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 17:38:25 by cschoen           #+#    #+#             */
/*   Updated: 2019/09/24 21:26:24 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flag.h"

static void	fractal(t_flg *flg, char *fractal, char *app_name)
{
	size_t	len;
	size_t	i;

	i = -1;
	len = ft_strlen(fractal);
	while (++i < len)
		fractal[i] = ft_tolower(fractal[i]);
	if (!ft_strcmp(fractal, "mandelbrot"))
		flg->type = MANDELBROT;
	else if (!ft_strcmp(fractal, "burning_ship"))
		flg->type = BURNING_SHIP;
	else if (!ft_strcmp(fractal, "mandelbar"))
		flg->type = MANDELBAR;
	else if (!ft_strcmp(fractal, "celtic"))
		flg->type = CELTIC;
	else if (!ft_strcmp(fractal, "julia"))
		flg->type = JULIA;
	else if (!ft_strcmp(fractal, "newton"))
		flg->type = NEWTON;
	else
		lite_usage(app_name, 1);
}

static void	power(t_flg *flg, int ac, char **av, int i)
{
	size_t	len;

	flg->flag & F_POW ?
		err_usage("More than 1 power flag", av[0], flg->help) : 0;
	flg->flag |= F_POW;
	flg->args += 2;
	i >= ac - 2 ?
		err_usage("Incorrect use of the power flag\nTry '--power 2'",
			av[0], flg->help) : 0;
	len = ft_strlen(av[i + 1]);
	if (len < 1 || len > 2)
		err_usage("Incorrect use of the power flag", av[0], flg->help);
	flg->pow = ft_atoi(av[i + 1]);
	if (flg->pow < 2 || flg->pow > 99 || (flg->pow < 10 && len != 1) ||
		(flg->pow > 9 && len != 2))
		err_usage("Range for power must be in [2...99] inclusive",
				av[0], flg->help);
}

static void	flags(t_flg *flg, int ac, char **av)
{
	int	i;

	i = 0;
	while (++i < ac)
	{
		if (!ft_strcmp(av[i], "--color") || !ft_strcmp(av[i], "-c"))
			color(flg, ac, av, i);
		else if (!ft_strcmp(av[i], "--gradient") || !ft_strcmp(av[i], "-g"))
			gradient(flg, ac, av, i);
		else if (!ft_strcmp(av[i], "--max-iter") || !ft_strcmp(av[i], "-m"))
			max_iter(flg, ac, av, i);
		else if (!ft_strcmp(av[i], "--power") || !ft_strcmp(av[i], "-p"))
			power(flg, ac, av, i);
		else if (!ft_strcmp(av[i], "--size") || !ft_strcmp(av[i], "-s"))
			size(flg, ac, av, i);
		else if (!ft_strcmp(av[i], "--col-grad") || !ft_strcmp(av[i], "-X"))
			col_grad(flg, ac, av, i);
		else if (!ft_strcmp(av[i], "--zoom-exp") || !ft_strcmp(av[i], "-z"))
			zoom_exp(flg, ac, av, i);
		else if (!ft_strcmp(av[i], "-Re") || !ft_strcmp(av[i], "-Im"))
			complex(flg, ac, av, i);
		else if (!ft_strcmp(av[i], "-k-Re") || !ft_strcmp(av[i], "-k-Im"))
			complex(flg, ac, av, i);
	}
}

void		valid_stdin(t_flg *flg, int ac, char **av)
{
	int	i;

	i = 0;
	while (++i < ac)
	{
		!ft_strcmp(av[i], "--help") ? ++flg->args : 0;
		!ft_strcmp(av[i], "--help") ? flg->help = 1 : 0;
	}
	flags(flg, ac, av);
	if (ac != flg->args || flg->help)
		err_usage((ac == flg->args || (ac == 2 && flg->help) ? NULL :
			"Wrong arguments/source in program call"), av[0], flg->help);
	fractal(flg, av[ac - 1], av[0]);
}
