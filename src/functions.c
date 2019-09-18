/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 19:34:46 by cschoen           #+#    #+#             */
/*   Updated: 2019/09/18 03:54:40 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		choose_number(t_frac *ftl, int key)
{
	if (key == ONE_KEY)
		ftl->mem.color = 1;
	else if (key == TWO_KEY)
		ftl->mem.color = 2;
	else if (key == THREE_KEY)
		ftl->mem.color = 3;
	else if (key == FOUR_KEY)
		ftl->mem.color = 4;
	else if (key == FIVE_KEY)
		ftl->mem.color = 5;
	else if (key == SIX_KEY)
		ftl->mem.color = 6;
	else if (key == SEVEN_KEY)
		ftl->mem.color = 7;
	else if (key == EIGHT_KEY)
		ftl->mem.color = 8;
	else if (key == NINE_KEY)
		ftl->mem.color = 9;
	else if (key == ZERO_KEY)
		ftl->mem.color = 0;
	if ((ftl->type != NEWTON && ftl->mem.color > ftl->grad.col_cnt) ||
		(ftl->type == NEWTON && ftl->mem.color > ftl->root.cnt))
		ftl->mem.color = 0;
}

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
