/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ui.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 21:50:21 by cschoen           #+#    #+#             */
/*   Updated: 2019/09/24 21:25:32 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		draw_current(t_frac *ftl, int *y, char *str, char *temp)
{
	!(str = ft_strnew(28)) ? error("No memory allocated for UI") : 0;
	!(temp = ft_itoa(ftl->mem.color)) ? error("No memory allocated for UI") : 0;
	ft_strcpy(str, ftl->type == NEWTON ? "Current root: " : "Current color: ");
	draw_str(ftl, 5, y, ft_strcat(str, temp));
	ft_strdel(&temp);
	if (ftl->type == JULIA || ftl->type == NEWTON)
	{
		ft_strcat(ft_strcpy(str, "Zoom: "), ftl->mem.mouse_zoom ? "On" : "Off");
		draw_str(ftl, 5, y, str);
		ft_strcpy(str, ftl->type == JULIA ? "Auto K: " : "Auto Root: ");
		draw_str(ftl, 5, y, ft_strcat(str, ftl->mem.mouse_hook ? "On" : "Off"));
	}
	if (ftl->type == NEWTON)
	{
		temp = ft_dtoa(ftl->root.damping.re);
		draw_str(ftl, 5, y, ft_strcat(ft_strcpy(str, "Bamping: "), temp));
		ft_strdel(&temp);
	}
	if (ftl->type == JULIA)
	{
		*y += 20;
		draw_str(ftl, 5, y, "K:");
		draw_complex(ftl, &ftl->k, 10, y);
	}
	ft_strdel(&str);
}

static void	draw_keys2(t_frac *ftl, int *y)
{
	draw_str(ftl, 10, y, "Roots(max 5): + -;");
	draw_str(ftl, 10, y, "Power: + -;");
	draw_str(ftl, 10, y, "Switch colors:");
	draw_str(ftl, 20, y, "Left Shift/Ctrl;");
	draw_str(ftl, 10, y, "Choose color:");
	draw_str(ftl, 15, y, "All: 0;");
	draw_str(ftl, 15, y, "Certain: 1-9;");
	*y += 20;
	draw_str(ftl, 10, y, "Change RGB of color: Right Shift/Ctrl;");
	draw_str(ftl, 10, y, "Change Red|Green|Blue of color: Q A|W S|E D;");
	*y += 20;
	draw_str(ftl, 10, y, "Change Damping Number(NEWTON): < >;");
	draw_str(ftl, 10, y, "Change Max Iterations(Color = 0): < >;");
	draw_str(ftl, 10, y, "Change Gradient(Color [1-max color count]): < >;");
	draw_str(ftl, 10, y, "Change Image Size: F1 F2;");
	*y += 20;
	draw_str(ftl, 10, y, "Exit: Esc");
}

static void	draw_keys(t_frac *ftl, int *y)
{
	*y = 50;
	draw_str(ftl, 205, y, "NUMPAD:");
	draw_str(ftl, 210, y, "Fast move: {2, 4, 6, 8};");
	draw_str(ftl, 210, y, "Zoom: + -; Fast zoom: * /;");
	draw_str(ftl, 210, y, "Centralize(default/custom):");
	draw_str(ftl, 210, y, "Zoom: 1 0; Camera: Enter 5;");
	draw_str(ftl, 210, y, "Color mode: dot;");
	*y += 20;
	draw_str(ftl, 205, y, "MOUSE:");
	draw_str(ftl, 210, y, "Move dot to center: LMC;");
	draw_str(ftl, 210, y, "Zoom: Scroll;");
	draw_str(ftl, 210, y, "K(Julia)/Root(Newton):Scroll;");
	draw_str(ftl, 210, y, "Scroll mode: Scroll click;");
	draw_str(ftl, 210, y, "Auto K/Root: RMC;");
	draw_str(ftl, 210, y, "Choose side fractal: LMC;");
	*y = 50;
	draw_str(ftl, 5, y, "KEYBOARD:");
	draw_str(ftl, 10, y, "Move: Arrows;");
	draw_str(ftl, 10, y, "Fractals:");
	draw_str(ftl, 15, y, "Prev/Next: F G;");
	draw_str(ftl, 15, y, "On/Off other: M;");
	draw_str(ftl, 10, y, "Center: Space;");
	draw_str(ftl, 10, y, "Psycho: P;");
	draw_str(ftl, 10, y, "Output cmd: O;");
	draw_keys2(ftl, y);
}

void		draw_ui(t_frac *ftl)
{
	char	*str;
	char	*temp;
	int		y;

	str = NULL;
	temp = NULL;
	y = 5;
	mlx_put_image_to_window(ftl->mlx_ptr, ftl->win_ptr,
							ftl->black_img->img_ptr, -1, 0);
	ftl->type == MANDELBROT ? draw_str(ftl, 5, &y, "Mandelbrot") : 0;
	ftl->type == BURNING_SHIP ? draw_str(ftl, 5, &y, "Burning Ship") : 0;
	ftl->type == MANDELBAR ? draw_str(ftl, 5, &y, "Mandelbar") : 0;
	ftl->type == CELTIC ? draw_str(ftl, 5, &y, "Celtic") : 0;
	ftl->type == JULIA ? draw_str(ftl, 5, &y, "Julia") : 0;
	ftl->type == NEWTON ? draw_str(ftl, 5, &y, "Newton") : 0;
	y = 25;
	draw_str(ftl, 5, &y, ftl->mem.ui ?
		"TAB - switch to keys" : "TAB - switch to info");
	y = 50;
	ftl->mem.ui ? draw_info(ftl, &y, str, temp) : draw_keys(ftl, &y);
}
