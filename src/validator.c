/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 17:38:25 by cschoen           #+#    #+#             */
/*   Updated: 2019/09/08 21:55:15 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
	else if (!ft_strcmp(fractal, "julia"))
		flg->type = JULIA;
	else
		lite_usage(app_name, 1);
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

static void	valid_stdin(t_flg *flg, int ac, char **av)
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
}

void		init_flg(t_flg *flg, int ac, char **av)
{
	flg->help = 0;
	flg->flag = 0;
	flg->args = 2;
	flg->size = 500;
	flg->iter = 100;
	flg->grad.col_cnt = 3;
	flg->grad.range[0] = 1;
	flg->grad.range[1] = 0.5;
	flg->grad.range[2] = 0;
	hex_to_rgb("f", &flg->grad.col[0]);
	hex_to_rgb("8", &flg->grad.col[1]);
	hex_to_rgb("0", &flg->grad.col[2]);
	flg->cam = set_complex(0, 0);
	flg->zoom = 1;
	flg->k = set_complex(-0.79, 0.15);
	valid_stdin(flg, ac, av);
	fractal(flg, av[ac - 1], av[0]);
	flg->app = av[0];
}
