/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 21:40:25 by cschoen           #+#    #+#             */
/*   Updated: 2019/09/22 18:35:11 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	draw_color(t_frac *ftl, t_rgb *color, int x, int y)
{
	char	*str;
	char	*temp;

	if (!(str = ft_strnew(15)))
		error("No memory allocated for UI");
	ft_memset(str, (int)' ', 15);
	str[0] = '{';
	if (!(temp = ft_itoa((int)(color->r > 255 ? 511 - color->r : color->r))))
		error("No memory allocated for UI");
	ft_strcpy(&str[4 - ft_strlen(temp)], temp);
	ft_strdel(&temp);
	if (!(temp = ft_itoa((int)(color->g > 255 ? 511 - color->g : color->g))))
		error("No memory allocated for UI");
	ft_strcpy(&str[9 - ft_strlen(temp)], temp);
	ft_strdel(&temp);
	if (!(temp = ft_itoa((int)(color->b > 255 ? 511 - color->b : color->b))))
		error("No memory allocated for UI");
	ft_strcpy(&str[14 - ft_strlen(temp)], temp);
	ft_strdel(&temp);
	str[4] = ',';
	str[9] = ',';
	str[14] = '}';
	draw_str(ftl, x, &y, str);
	ft_strdel(&str);
}

char		*ft_dtoa(double num)
{
	char	*str;
	char	*temp;
	int		i;

	i = 0;
	if (!(str = ft_strnew(19)))
		error("No memory allocated for string");
	if (!(temp = ft_itoa((int)num)))
		error("No memory allocated for string");
	i += (int)ft_strlen(temp);
	ft_strcpy(&str[i], temp);
	ft_strdel(&temp);
	num = fabs((num - (int)num)) * 100000000;
	if (!(temp = ft_itoa((int)num)))
		error("No memory allocated for string");
	num = (num - (int)num) * 10000000;
	if ((int)num != 0)
	{
		str[i++] = '.';
		ft_strncpy(&str[i], "00000000", (size_t)(8 - ft_strlen(temp)));
		ft_strcpy(&str[i + (8 - ft_strlen(temp))], temp);
		i += 8;
		ft_strdel(&temp);
		if (!(temp = ft_itoa((int)num)))
			error("No memory allocated for string");
	}
	if (*temp == '0')
	{
		ft_strdel(&temp);
		return (str);
	}
	(int)num == 0 ? str[i++] = '.' : 0;
	ft_strncpy(&str[i], "00000000", (size_t)((int)num == 0 ? 8 : 7) - ft_strlen(temp));
	ft_strcpy(&str[i + (((int)num == 0 ? 8 : 7) - ft_strlen(temp))], temp);
	ft_strdel(&temp);
	return (str);
}

static void	draw_root(t_frac *ftl, t_complex *root, int i, int *y)
{
	char	*str;
	char	*temp;

	if (!(str = ft_strnew(25)))
		error("No memory allocated for UI");
	str[0] = i + '1';
	ft_strcat(str, ") Re: ");
	temp = ft_dtoa(root->re);
	ft_strcat(str, temp);
	ft_strdel(&temp);
	draw_str(ftl, 10, y, str);
	ft_strcpy(str, "   Im: ");
	temp = ft_dtoa(root->im);
	ft_strcat(str, temp);
	ft_strdel(&temp);
	draw_str(ftl, 10, y, str);
	ft_strdel(&str);
}

static void	draw_info2(t_frac *ftl, int i, int *y)
{
	char	*str;

	if (ftl->type != NEWTON)
	{
		draw_str(ftl, 5, y, "Grad:  Color:");
		while (++i < ftl->grad.col_cnt)
		{
			if (!(str = ft_itoa((int)(ftl->grad.range[i] * 1000))))
				error("No memory allocated for UI");
			draw_str(ftl, 10, y, str);
			ft_strdel(&str);
			draw_color(ftl, &ftl->grad.col[i], 80, *y - 20);
		}
	}
	else
	{
		draw_str(ftl, 5, y, "Roots:");
		while (++i < ftl->root.cnt)
		{
			draw_root(ftl, &ftl->root.roots[i], i, y);
			draw_color(ftl, &ftl->root.cols[i], 200, *y - 40);
		}
	}
}

void		draw_info(t_frac *ftl)
{
	int	y;

	y = 60;
	draw_info2(ftl, -1, &y);
	ft_putstr("  Center:\n    Re: ");
	print_double(ftl->cam.re);
	ft_putstr("\n    Im: ");
	print_double(ftl->cam.im);
	if (ftl->type == JULIA)
	{
		ft_putstr("\n  k:\n    Re: ");
		print_double(ftl->k.re);
		ft_putstr("\n    Im: ");
		print_double(ftl->k.im);
	}
	ft_putstr("\n  Max iter: ");
	ft_putnbr(ftl->iter);
	ft_putendl("");
	ftl->type == NEWTON ? ft_putstr("  Roots: ") : ft_putstr("  Z-Power: ");
	ft_putnbr(ftl->pow);
	ft_putendl("\n");
}
