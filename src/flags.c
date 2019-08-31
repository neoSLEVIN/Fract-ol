/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 17:38:25 by cschoen           #+#    #+#             */
/*   Updated: 2019/09/01 02:19:45 by cschoen          ###   ########.fr       */
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

static void	max_iter(t_flg *flg, int ac, char **av, int i)
{
	size_t	len;

	flg->flag & F_MIT ?
		err_usage("More than 1 iteration flag", av[0], flg->help) : 0;
	flg->flag |= F_MIT;
	flg->args += 2;
	i >= ac - 2 ?
		err_usage("Incorrect use of the iteration flag\nTry '--max-iter 100'",
			av[0], flg->help) : 0;
	len = ft_strlen(av[i + 1]);
	if (len < 1 || len > 3)
		err_usage("Incorrect use of the iteration flag", av[0], flg->help);
	flg->iter = ft_atoi(av[i + 1]);
	if (flg->iter < 2 || flg->iter > 500 || (flg->iter < 10 && len != 1) ||
		(flg->iter > 9 && flg->iter < 100 && len != 2) ||
		(flg->iter > 99 && len != 3))
		err_usage("Range for iteration must be in [2...500]", av[0], flg->help);
}

static void	size(t_flg *flg, int ac, char **av, int i)
{
	size_t	len;

	flg->flag & F_SIZ ?
		err_usage("More than 1 size flag", av[0], flg->help) : 0;
	flg->flag |= F_SIZ;
	flg->args += 2;
	i >= ac - 2 ?
		err_usage("Incorrect use of the size flag\nTry '--size 500'",
			av[0], flg->help) : 0;
	len = ft_strlen(av[i + 1]);
	if (len < 3 || len > 4)
		err_usage("Incorrect use of the size flag\nTry '-s 500'",
			av[0], flg->help);
	flg->size = ft_atoi(av[i + 1]);
	if (flg->size < 150 || flg->size > 1500 || (flg->size < 1000 && len != 3))
		err_usage("Range for size must be in [150...1500]", av[0],
			flg->help);
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
	}
	if (ac != flg->args || flg->help)
		err_usage((ac == flg->args || (ac == 2 && flg->help) ? NULL :
			"Wrong arguments/source in program call"), av[0], flg->help);
}

void		init_flg(t_flg *flg, int ac, char **av)
{
	flg->help = 0;
	flg->flag = 0;
	flg->args = 2;
	flg->size = WIN_SIZE;
	flg->iter = MAX_ITER;
	flg->col_cnt = 3;
	flg->grad.range[0] = 0;
	flg->grad.range[1] = 0.5;
	flg->grad.range[2] = 1;
	hex_to_rgb("0", &flg->grad.col[0]);
	hex_to_rgb("8", &flg->grad.col[1]);
	hex_to_rgb("f", &flg->grad.col[2]);
	valid_stdin(flg, ac, av);
	fractal(flg, av[ac - 1], av[0]);
}
