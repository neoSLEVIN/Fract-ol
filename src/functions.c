/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 19:34:46 by cschoen           #+#    #+#             */
/*   Updated: 2019/09/08 06:52:14 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

long long	ft_atoll(char *num, size_t len)
{
	long long	temp;

	if (len < 10)
		return (ft_atoi(num));
	temp = ft_atoi(num + (len - 9));
	num[len - 9] = '\0';
	return (ft_atoi(num) * (long long)pow(10, 9) + temp);
}

static int	atoi16(char *num, int char_cnt)
{
	int	digit[2];
	int	i;

	i = -1;
	while (++i < 2)
	{
		if (*num >= '0' && *num <= '9')
			digit[i] = *num - 48;
		else if (*num >= 'A' && *num <= 'F')
			digit[i] = *num - 55;
		else if (*num >= 'a' && *num <= 'f')
			digit[i] = *num - 87;
		else
			digit[i] = 0;
		char_cnt == 2 ? ++num : 0;
	}
	return (16 * digit[0] + digit[1]);
}

void		hex_to_rgb(char *hex, t_rgb *color)
{
	size_t	len;

	len = ft_strlen(hex);
	if (len == 1)
		*color = set_rgb(atoi16(hex, 1), atoi16(hex, 1), atoi16(hex, 1));
	else if (len == 3)
		*color =
			set_rgb(atoi16(hex, 1), atoi16(&hex[1], 1), atoi16(&hex[2], 1));
	else if (len == 6)
		*color =
			set_rgb(atoi16(hex, 2), atoi16(&hex[2], 2), atoi16(&hex[4], 2));
}

void		plot(t_img *img, t_point coord, t_rgb color)
{
	int		*i;

	i = (int *)img->data;
	color.r > 255 ? color.r = 511 - color.r : 0;
	color.g > 255 ? color.g = 511 - color.g : 0;
	color.b > 255 ? color.b = 511 - color.b : 0;
	i[coord.y * img->size.x + coord.x] = color.r << 16 | color.g << 8 | color.b;
}
