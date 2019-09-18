/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 16:42:53 by cschoen           #+#    #+#             */
/*   Updated: 2019/09/17 21:35:08 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			max_iter(t_flg *flg, int ac, char **av, int i)
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
	if (len < 1 || len > 4)
		err_usage("Incorrect use of the iteration flag", av[0], flg->help);
	flg->iter = ft_atoi(av[i + 1]);
	if (flg->iter < 2 || flg->iter > 2000 || (flg->iter < 10 && len != 1) ||
		(flg->iter > 9 && flg->iter < 100 && len != 2) ||
		(flg->iter > 99 && flg->iter < 1000 && len != 3) ||
		(flg->iter > 999 && len != 4))
		err_usage("Range for iteration must be in [2...2000] inclusive",
				av[0], flg->help);
}

void			size(t_flg *flg, int ac, char **av, int i)
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

void			zoom_exp(t_flg *flg, int ac, char **av, int i)
{
	size_t	len;

	flg->flag & F_ZOM ?
		err_usage("More than 1 exponential zoom flag", av[0], flg->help) : 0;
	flg->flag |= F_ZOM;
	flg->args += 2;
	i >= ac - 2 ?
		err_usage("Incorrect use of the exponential zoom flag\nTry '--z 0'",
				av[0], flg->help) : 0;
	len = ft_strlen(av[i + 1]);
	if (len < 1 || len > 2)
		err_usage("Incorrect use of the exponential zoom flag",
			av[0], flg->help);
	flg->zoom = ft_atoi(av[i + 1]);
	if (flg->zoom < 0 || flg->zoom > 99 ||
		(flg->zoom < 10 && len != 1) || (flg->zoom > 9 && len != 2))
		err_usage("Range for exponential zoom must be in [0...99] inclusive",
			av[0], flg->help);
	flg->zoom = pow(10.0, flg->zoom);
}

static double	set_value(t_flg *flg, char **av, int i, size_t len)
{
	int			neg;
	int			value;
	long long	rest;
	size_t		j;

	len = ft_strlen(av[i + 1]);
	if (len < 1 || len > 18)
		err_usage("Incorrect use of the complex number flag", av[0], flg->help);
	neg = (av[i + 1][0] == '-') ? 1 : 0;
	neg ? --len : 0;
	if (!len || (len == 1 && !ft_isdigit(av[i + 1][0 + neg])))
		err_usage("Incorrect complex number value", av[0], flg->help);
	if (len == 1)
		return ((av[i + 1][0 + neg] - '0') * (neg ? -1 : 1));
	--len;
	if (av[i + 1][1 + neg] != '.' || (--len == 0) || len > 15)
		err_usage("Incorrect complex number value", av[0], flg->help);
	j = -1;
	while (++j < len)
		if (!ft_isdigit(av[i + 1][j + 2 + neg]))
			err_usage("Incorrect complex number value", av[0], flg->help);
	value = (av[i + 1][0 + neg] - '0');
	rest = ft_atoll(&av[i + 1][2 + neg], len);
	return ((value + (double)rest / (long long)pow(10, len)) * (neg ? -1 : 1));
}

void			complex(t_flg *flg, int ac, char **av, int i)
{
	if (av[i][1] == 'R' && flg->flag & F_REC)
		err_usage("More than 1 -Re flag", av[0], flg->help);
	else if (av[i][1] == 'I' && flg->flag & F_IMC)
		err_usage("More than 1 -Im flag", av[0], flg->help);
	else if (av[i][3] == 'R' && flg->flag & F_REK)
		err_usage("More than 1 -k-Re flag", av[0], flg->help);
	else if (av[i][3] == 'I' && flg->flag & F_IMK)
		err_usage("More than 1 -k-Im flag", av[0], flg->help);
	flg->flag |= (av[i][1] == 'R') ? F_REC : 0;
	flg->flag |= (av[i][1] == 'I') ? F_IMC : 0;
	flg->flag |= (av[i][3] == 'R') ? F_REK : 0;
	flg->flag |= (av[i][3] == 'I') ? F_IMK : 0;
	flg->args += 2;
	i >= ac - 2 ? err_usage("Incorrect use of the complex number flag",
							av[0], flg->help) : 0;
	if (av[i][1] == 'R')
		flg->cam.re = set_value(flg, av, i, ft_strlen(av[i + 1]));
	else if (av[i][1] == 'I')
		flg->cam.im = set_value(flg, av, i, ft_strlen(av[i + 1]));
	else if (av[i][3] == 'R')
		flg->k.re = set_value(flg, av, i, ft_strlen(av[i + 1]));
	else if (av[i][3] == 'I')
		flg->k.im = set_value(flg, av, i, ft_strlen(av[i + 1]));
}
