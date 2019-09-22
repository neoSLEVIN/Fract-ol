/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 19:34:46 by cschoen           #+#    #+#             */
/*   Updated: 2019/09/22 22:25:27 by cschoen          ###   ########.fr       */
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

void		print_double(double num)
{
	char	*s;

	s = ft_dtoa(num);
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

void		draw_str(t_frac *ftl, int x, int *y, char *str)
{
	mlx_string_put(ftl->mlx_ptr, ftl->win_ptr, x, *y + LM, 0x00cccccc, str);
	*y += 20;
}
