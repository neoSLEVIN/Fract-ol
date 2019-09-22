/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 21:40:25 by cschoen           #+#    #+#             */
/*   Updated: 2019/09/22 22:33:32 by cschoen          ###   ########.fr       */
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

static void	draw_complex(t_frac *ftl, t_complex *complex, int x, int *y)
{
	char	*str;
	char	*temp;

	if (!(str = ft_strnew(50)))
		error("No memory allocated for UI");
	ft_strcat(str, "Re: ");
	temp = ft_dtoa(complex->re);
	ft_strcat(str, temp);
	ft_strdel(&temp);
	draw_str(ftl, x, y, str);
	ft_strcpy(str, "Im: ");
	temp = ft_dtoa(complex->im);
	ft_strcat(str, temp);
	ft_strdel(&temp);
	draw_str(ftl, x, y, str);
	ft_strdel(&str);
}

static void	draw_root(t_frac *ftl, t_complex *root, int i, int *y)
{
	char	str[3];

	str[0] = i + '1';
	str[1] = ')';
	str[2] = '\0';
	draw_str(ftl, 270, y, str);
	*y -= 20;
	draw_complex(ftl, root, 290, y);
	*y += 20;
}

static void	draw_info2(t_frac *ftl, int i, int *y, char *str)
{
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
		draw_str(ftl, 10, y, "Color:");
		*y -= 20;
		draw_str(ftl, 270, y, "Number:");
		while (++i < ftl->root.cnt)
		{
			draw_root(ftl, &ftl->root.roots[i], i, y);
			draw_color(ftl, &ftl->root.cols[i], 10, *y - 60);
		}
	}
}

void		draw_info(t_frac *ftl, char *str, int *y)
{
	draw_str(ftl, 5, y, "Center:");
	draw_complex(ftl, &ftl->cam, 10, y);
	*y += 20;
	draw_str(ftl, 5, y, "Max iterations:");
	*y -= 20;
	if (!(str = ft_itoa(ftl->iter)))
		error("No memory allocated for UI");
	draw_str(ftl, 170, y, str);
	ft_strdel(&str);
	if (ftl->type == JULIA)
	{
		draw_str(ftl, 5, y, "K:");
		draw_complex(ftl, &ftl->k, 10, y);
		*y += 20;
	}
	draw_str(ftl, 5, y, ftl->type == NEWTON ? "Roots:" : "Power:");
	if (!(str = ft_itoa(ftl->type == NEWTON ? ftl->root.cnt : ftl->pow)))
		error("No memory allocated for UI");
	*y -= 20;
	draw_str(ftl, 75, y, str);
	ft_strdel(&str);
	*y += 20;
	draw_current(ftl, y, str);
	draw_info2(ftl, -1, y, str);
}
