/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 19:34:46 by cschoen           #+#    #+#             */
/*   Updated: 2019/09/18 07:15:38 by cschoen          ###   ########.fr       */
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

void		new_image(t_frac *ftl, int size)
{
	if (!(ftl->img = (t_img*)malloc(sizeof(t_img))))
		error("No memory allocated for new image");
	if (!(ftl->img->img_ptr = mlx_new_image(ftl->mlx_ptr, size, size)))
		error("Failed to create a new image");
	ftl->img->data = mlx_get_data_addr(ftl->img->img_ptr, &ftl->img->bpp,
									&ftl->img->size_line, &ftl->img->endian);
	ftl->img->size.x = size;
	ftl->img->size.y = size;
}
