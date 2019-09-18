/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 15:35:49 by cschoen           #+#    #+#             */
/*   Updated: 2019/09/17 21:38:19 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_rgb		set_rgb(int red, int green, int blue)
{
	t_rgb	color;

	color.r = red;
	color.g = green;
	color.b = blue;
	return (color);
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

void		print_hex(t_rgb color)
{
	ft_putstr("0x");
	color.r > 255 ? color.r = 511 - color.r : 0;
	color.g > 255 ? color.g = 511 - color.g : 0;
	color.b > 255 ? color.b = 511 - color.b : 0;
	if (color.r / 16 == color.r % 16 && color.g / 16 == color.g % 16 &&
		color.b / 16 == color.b % 16)
	{
		if (color.r == color.g && color.r == color.b)
			print_itoa16(color.r, 0);
		else
		{
			print_itoa16(color.r, 0);
			print_itoa16(color.g, 0);
			print_itoa16(color.b, 0);
		}
	}
	else
	{
		print_itoa16(color.r, 1);
		print_itoa16(color.g, 1);
		print_itoa16(color.b, 1);
	}
}

int			rgbcmp(t_rgb rgb1, t_rgb rgb2)
{
	rgb1.r > 255 ? rgb1.r = 511 - rgb1.r : 0;
	rgb1.g > 255 ? rgb1.g = 511 - rgb1.g : 0;
	rgb1.b > 255 ? rgb1.b = 511 - rgb1.b : 0;
	rgb2.r > 255 ? rgb2.r = 511 - rgb2.r : 0;
	rgb2.g > 255 ? rgb2.g = 511 - rgb2.g : 0;
	rgb2.b > 255 ? rgb2.b = 511 - rgb2.b : 0;
	return (!(rgb1.r == rgb2.r || rgb1.g == rgb2.g || rgb1.b == rgb2.b));
}
