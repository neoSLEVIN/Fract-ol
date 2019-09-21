/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 19:34:46 by cschoen           #+#    #+#             */
/*   Updated: 2019/09/21 23:37:37 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		print_itoa16(short num, _Bool full)
{
	num > 255 ? num = 511 - num : 0;
	if (num / 16 < 10)
		ft_putnbr(num / 16);
	else
		ft_putchar(num / 16 + 87);
	if (full)
	{
		if (num % 16 < 10)
			ft_putnbr(num % 16);
		else
			ft_putchar(num % 16 + 87);
	}
}

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

long long	ft_atoll(char *num, size_t len)
{
	long long	temp;

	if (len < 10)
		return (ft_atoi(num));
	temp = ft_atoi(num + (len - 9));
	num[len - 9] = '\0';
	return (ft_atoi(num) * (long long)pow(10, 9) + temp);
}

int			is_hex(char *hex)
{
	int	i;

	i = 1;
	if (!*hex)
		return (0);
	if (*hex != '0' || *(hex + 1) != 'x')
		return (0);
	while (++i < 8 && *(hex + i))
		if (!((*(hex + i) >= '0' && *(hex + i) <= '9') ||
				(*(hex + i) >= 'A' && *(hex + i) <= 'F') ||
				(*(hex + i) >= 'a' && *(hex + i) <= 'f')))
			return (0);
	return ((!*(hex + i) && (i == 8 || i == 5 || i == 3)) ? 1 : 0);
}
